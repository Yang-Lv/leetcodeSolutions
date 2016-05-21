#include <iostream>

using namespace std;

class Solution{
public:
    int myAtoi(string str){
        int len=str.size();
        int flag=1;
        long result=0;
        int i=0;
        //忽略开始的空格符
        while(i<len){
            if(str[i]==' ')
                i++;
            else
                break;
        }
        if(i>=len) return 0;
        if(str[i]=='+'){
            i++;
            flag=1;
        }else if(str[i]=='-'){
            i++;
            flag=-1;
        }else if(str[i]<'0' || str[i]>'9'){
            return 0;
        }
        while(i<len){
            if(str[i]<'0' || str[i]>'9') break;
            int tmp=str[i]-'0';
            result=result*10+tmp;
            if(flag==1 && result>=INT32_MAX) return INT32_MAX;
            if(flag==-1){
                if(result>INT32_MAX)
                    return INT32_MIN;
            }
            i++;
        }
        return  flag*result;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    Solution ss;
    cout<<ss.myAtoi("-21474836471")<<endl;
    long t=-1*INT32_MAX;
    cout<<t<<endl;
    return 0;
}