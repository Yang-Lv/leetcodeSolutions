#include <iostream>

using namespace std;

class Solution{
public:
    int reverse(int x){
        long result=0;
        int flag=x>0?1:-1;
        x*=flag;
        while(x>0){
            int tmp=x%10;
            result=result*10+tmp;
            x/=10;
        }
        if(result>INT32_MAX)
            return 0;
        return flag*result;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    cout<<INT32_MIN*-1<<endl;
    return 0;
}