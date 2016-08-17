#include <iostream>

using namespace std;

class Solution{
public:
    int longestValidParentheses(string s){
        int maxLen=0,slen,i=0;
        string ss;
        //remove all ')' at the head of string
        while(s[i]==')') i++;
        ss=s.substr(i);
        slen=ss.length();
        if(!slen) return 0;
        //init dp: dp[i] is the length of parentheses which is end with s[i]
        int *dp=new int[slen];
        for(int j=0;j<slen;j++) dp[j]=0;
        //dp
        for(i=1;i<slen;i++){
            if(ss[i]==')'){
                if(i-1-dp[i-1]>=0 && ss[i-1-dp[i-1]]=='('){
                    dp[i]=dp[i-1]+2;
                    //judge the adjacent whether is valid: Yes:add;No:pass
                    if(i-2-dp[i-1]>=0){
                        dp[i]+=dp[i-2-dp[i-1]];
                    }
                    if(dp[i]>maxLen){
                        maxLen=dp[i];
                    }
                }
            }
        }
        return maxLen;
    }
};
int main() {
    Solution s;
    cout<<s.longestValidParentheses("()()");
    return 0;
}