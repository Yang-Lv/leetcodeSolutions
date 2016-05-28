#include <string.h>
#include <iostream>
using namespace std;

class Solution{
public:
    string longestPalindrome(string s){
        //Dynamic Programming
        //time complexity:O(n^2)
        //dp[i][j]:s[i]-s[j] is Palindrome
        string result;
        int maxLen=0;
        const int len=s.size();
        if(len==0)
            return result;
        if(len==1)
            return s;
        bool dp[len][len];
        memset(dp, false,sizeof(bool)*len*len);
        //init dp,such that i<=j
        for(int i=0;i<len;i++)
            dp[i][i]= true;
        //dynamic programming process
        int k=2;//indicate the length of string which is waitting for judge whether it is a palindrome
        for(int i=0;i<=len-2;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]= true;
                if(maxLen<2){
                    result=s.substr(i,2);
                    maxLen=2;
                }
            }
        }
        k++;
        for(;k<=len;k++){
            for(int i=0;i<=len-k;i++){
                //judge dp[i][i+k-1] if it is a palindrome
                int j=i+k-1;
                if(dp[i+1][j-1] && s[i]==s[j]){
                    dp[i][j]= true;
                    if(maxLen<k){
                        result=s.substr(i,k);
                        maxLen=k;
                    }
                }
            }
        }
        return result;
    }
    //the second method
    string longestPalindrome2(string s){
        string result;
        int maxLen=0;
        int len=s.size();
        if(len==0 || len==1)
            return s;
        //for each c in s,let c as the center or c,c+1 as the center,find the longest Palindrome
        for(int i=0;i<len;i++){
            //think the palindrome's length is odd
            int a=i-1,b=i+1;
            while(a>=0 && b<len && s[a]==s[b]){
                int tmp=b-a+1;
                if(tmp>maxLen){
                    maxLen=tmp;
                    result=s.substr(a,tmp);
                }
                a--;b++;
            }
            //think the palindrome's length is even
            a=i,b=i+1;
            while(a>=0 && b<len && s[a]==s[b]){
                int tmp=b-a+1;
                if(tmp>maxLen){
                    maxLen=tmp;
                    result=s.substr(a,tmp);
                }
                a--;b++;
            }
        }
        return result;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    Solution ss;
    cout<<ss.longestPalindrome2("aaabaaaa")<<endl;
    return 0;
}