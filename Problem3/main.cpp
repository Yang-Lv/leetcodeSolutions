#include <iostream>
#include <string.h>
using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        //here I use an array to record the last index of c in s
        //you can think there are two pointers i and j which is before and the other is behind.
        //s[i-j]:is the substring which is satisfied with the constraint
        const int len=s.size();
        int max=0;
        if(len==0)
            return 0;
        int pre[256];
        memset(pre,-1,sizeof(int)*256);
        int i,j;
        j=0;
        for(i=0;i<len;i++){
            if(pre[s[i]]==-1 || pre[s[i]]<j){
                int tmp=i-j+1;
                if(tmp>max){
                    max=tmp;
                }
            }else{
                j=pre[s[i]]+1;
                if(i-j+1>max){
                    max=i-j+1;
                }
            }
            pre[s[i]]=i;
        }
        if(i-j>max){
            max=i-j;
        }
        return max;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    Solution ss;
    cout<<ss.lengthOfLongestSubstring("abba");
    return 0;
}