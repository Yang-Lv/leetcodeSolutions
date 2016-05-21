#include <iostream>

using namespace std;

class Solution{
public:
    bool isPalindrome(int x){
        long xx=0;
        if(x<0)
            return false;
        int t=x;
        while(x>0){
            int tmp=x%10;
            xx=xx*10+tmp;
            x/=10;
        }
        if(xx==t)
            return true;
        return false;
    }
};

int main() {
    cout<<sizeof(long)<<endl;
    cout << "Hello, World!" << endl;
    return 0;
}