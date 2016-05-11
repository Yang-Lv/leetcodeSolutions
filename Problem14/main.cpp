#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string> &strs){
        int len=strs.size();
        if(len==0)
            return "";
        for(int i=0;i<len;i++)
            if(strs[i].size()==0)
                return "";
        if(len==1)
            return strs[0];
        string refer=strs[0];
        string res;
        for(int i=0;i<refer.size();i++){
            char tmp=refer[i];
            bool flag= true;
            for(int j=1;j<len;j++){
                if(strs[j][i]!=tmp){
                    flag= false;
                    break;
                }
            }
            if(flag){
                res.push_back(tmp);
            }else{
                break;
            }
        }
        if(res.size()==0){
            return "";
        }else{
            return res;
        }
    }
};

int main() {
    Solution ss;
    vector<string> src;
    string a="az";
    string b="abc";
    src.push_back(a);
    src.push_back(b);
    string res=ss.longestCommonPrefix(src);
    cout<<res<<":"<<res.size()<<endl;
    return 0;
}