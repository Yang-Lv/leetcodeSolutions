#include <iostream>
#include <map>
using namespace std;

class Solution{
public:
    int romanToInt(string s){
        int len=s.size();
        int i=0;
        int result=0;
        bool flag=true;//用来判断左右方向的，例如：true:MC，false:CM
        map<char,int> map;
        //构造罗马字母与数字的对应表
        map.insert(pair<char,int>('I',1));
        map.insert(pair<char,int>('V',5));
        map.insert(pair<char,int>('X',10));
        map.insert(pair<char,int>('L',50));
        map.insert(pair<char,int>('C',100));
        map.insert(pair<char,int>('D',500));
        map.insert(pair<char,int>('M',1000));
        if(len==0) return 0;
        while(i<len){
//            map<char,int>::iterator it=map.find(s[i]);
            int num=1;
            int l=map.find(s[i])->second;
            int j=i+1;
            while(j<len && s[j]==s[i]){
                num++;
                j++;
            }
            if(j>=len){
                result+=num*l;
                i=j;
                continue;
            }
            int r=(map.find(s[j]))->second;
            if(r>l){
                if(num==1){
                    result+=r-l;
                    i=j+1;
                }else{
                    result+=num*l;
                    i=j;
                }
            }else{
                result+=num*l;
                i=j;
            }

        }
        return result;
    }
};
int main() {
    Solution ss;
    cout<<ss.romanToInt("DCXXI")<<endl;
    return 0;
}