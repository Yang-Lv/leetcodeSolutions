#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    string convert(string s,int numRows){
        int len=s.size();
        string result;
        if(len==0)
            return result;
        vector<vector<char>> t;
        t.resize(len>=numRows?numRows:len);
        int i=0,j=0;
        bool flag= true;
        while(i<len){
            //from top to bottom
            t[j].push_back(s[i]);
            if(flag){
                if(j==numRows-1){
                    j--;
                    flag=false;
                }else{
                    j++;
                }
            }else{
                if(j==0){
                    j++;
                    flag= true;
                }else{
                    j--;
                }
            }
            i++;
        }
        for(i=0;i<t.size();i++){
            vector<char> tmp=t[i];
            for(j=0;j<tmp.size();j++)
                result.push_back(tmp[j]);
        }
        return result;
    }
};

int main() {
    Solution ss;
    cout<<ss.convert("abc",1)<<endl;
    return 0;
}