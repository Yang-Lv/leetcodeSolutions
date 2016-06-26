#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<string> letterCombinations(string digits){
        vector<string> result;
        vector<string> map(10);
        map[2]="abc";
        map[3]="def";
        map[4]="ghi";
        map[5]="jkl";
        map[6]="mno";
        map[7]="pqrs";
        map[8]="tuv";
        map[9]="wxyz";
        int len=digits.size();
        if(len==0){
            return result;
        }
        int clen=0;
        for(int i=0;i<len;i++){
            int num=digits[i]-'0';
            string strNum=map[num];
            if(result.size()==0){
                for(int j=0;j<strNum.size();j++){
                    string tmp="";
                    tmp.push_back(strNum[j]);
                    result.push_back(tmp);
                }
                clen=1;
            }else{
                while(result.size()){
                    string t=result.front();
                    if(t.size()==clen){
                        result.erase(result.begin());
                        for(int k=0;k<strNum.size();k++) {
                            string tmp = t;
                            tmp.push_back(strNum[k]);
                            result.push_back(tmp);
                        }
                    }else{
                        break;
                    }
                }
                clen++;
            }
        }
        return result;
    }
};

void print(const string &a){
    cout<<a<<"  ";
}

int main() {
    Solution s;
    vector<string> res=s.letterCombinations("22");
    for_each(res.begin(),res.end(),print);
    cout<<endl;
//    vector<string> v;
//    v.push_back("lv");
//    v.push_back("yang");
//    v.erase(v.begin());
//    cout<<v.size()<<endl;
//    cout<<v[0];
    return 0;
}