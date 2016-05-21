#include <iostream>

using namespace std;

class Solution{
public:
    bool isMatch(string s,string p){
        int slen=s.size(),plen=p.size();
        int i,j;                                                 //       p
        const int len_s=slen+1,len_p=plen+1;                     //   s  |""| 1| 1-2| 1-3| ..
        bool dp[len_s][len_p];                                   //   "" |  |  |    |    |
        //init                                                   //    1 |  |  |    |    |
        dp[0][0]= true;                                          //   1-2|  |  |    |    |
        for(i=1;i<=slen;i++)                                     //   1-3|  |  |    |    |
            dp[i][0]=false;                                      //   ...|  |  |    |    |
        dp[0][1]= false;
        for(j=2;j<=plen;j++){
            dp[0][j]=dp[0][j-2] &&(p[j-1]=='*');
        }
        //dp process
        for(i=1;i<=slen;i++)
            for(j=1;j<=plen;j++){
                if(p[j-1]=='*'){
                    dp[i][j]=dp[i][j-2] || ((p[j-2]==s[i-1] || p[j-2]=='.') && dp[i-1][j]);
                }else{
                    dp[i][j]=(p[j-1]==s[i-1] || p[j-1]=='.') && dp[i-1][j-1];
                }
            }
        return dp[slen][plen];
    }
    bool match(string s,string p,int i,int j){
        if(j==-1)
            if(i==-1)
                return true;
            else
                return false;
        if(p[j]=='*'){
            if(i>-1 && p[j-1]=='.' || p[j-1]==s[i])
                if(match(s,p,i-1,j)){
                    return true;
                }
            return match(s,p,i,j-2);
        }
        if(p[j]==s[i] || p[j]=='.')
            return match(s,p,i-1,j-1);
        return false;

    }
    bool isMatch2(string s,string p){
        return match(s,p,s.size()-1,p.size()-1);
    }
};

int main() {
    cout << "Hello, World!" << endl;
    Solution ss;
    cout<<ss.isMatch("aab","c*a*b")<<endl;
    return 0;
}