#include <iostream>

using namespace std;

class Solution{
public:
    //naive method:slow
    int divide(int dividend,int divisor){
        if(divisor==0) return INT32_MAX;
        int f1=1,f2=1,f=1;
        long a=dividend,b=divisor,t=0,result=0;
        if(dividend<0){
            f1=-1;
            a=(long)dividend*-1;
        }
        if(divisor<0){
            f2=-1;
            b=(long)divisor*-1;
        }
        f=f1*f2;
        while(t<a){
            t+=b;
            result++;
        }
        if(t>a) result--;
        if(result>INT32_MAX && f>0) return INT32_MAX;
        if(result>(long)INT32_MAX+1 && f<0) return INT32_MIN;
        return f*result;
    }
    //faster method
    int divide2(int dividend,int divisor){
        if(!divisor) return INT32_MAX;
        if(dividend==INT32_MIN && divisor==-1) return INT32_MAX;
        int f=1;
        long a,b,res=0;
        a=labs(dividend);
        b=labs(divisor);
        f=(dividend<0)^(divisor<0)?-1:1;
        while(a>=b){
            long tmp=b,t=1;
            while(a>=tmp){
                t=t<<1;
                tmp=tmp<<1;
            }
            t=t>>1;
            tmp=tmp>>1;
            a-=tmp;
            res+=t;
        }
        return f*res;
    }
};
int main() {
    Solution s;
    cout<<s.divide2(1,1);
    return 0;
}