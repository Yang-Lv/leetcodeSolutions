#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    string intToRoman(int num){
        //I:1,V:5,X:10,L:50,C:100,D:500,M:1000
        string roman;
        vector<string> t;
        char f[]={'I','V','X','L','C','D','M'};
        int index=0;
        if(num<1 || num>3999) return "-1";
        while(num>0){
            int tmp=num%10;
            if(tmp>0&&tmp<5){
                string tt;
                if(tmp<=3){
                    for(int i=0;i<tmp;i++)
                        tt.push_back(f[index]);
                }else{
                    tt.push_back(f[index]);
                    tt.push_back(f[index+1]);
                }
                t.push_back(tt);
            }else if(tmp>5){
                int d=tmp-5;
                string tt;
                if(d<=3){
                    tt.push_back(f[index+1]);
                    for(int i=0;i<d;i++)
                        tt.push_back(f[index]);
                }else{
                    tt.push_back(f[index]);
                    tt.push_back(f[index+2]);
                }
                t.push_back(tt);
            }else if(tmp==5){
                string tt;
                tt.push_back(f[index+1]);
                t.push_back(tt);
            }
            index+=2;
            num/=10;
        }
        for(int i=t.size()-1;i>=0;i--)
            for(int j=0;j<t[i].length();j++)
                roman.push_back(t[i][j]);
        return roman;
    }

};

int main() {
    Solution ss;
    cout<<ss.intToRoman(99)<<endl;
    cout << "Hello, World!" << endl;
    return 0;
}