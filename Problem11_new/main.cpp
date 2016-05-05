#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int maxArea(vector<int> &height){
        int len=height.size();
        int i=0,j=len-1;
        int max=0;
        while(i<j){
            int tmp=(j-i)*min(height[i],height[j]);
            if(tmp>max)
                max=tmp;
            height[i]>height[j]?j--:i++;
        }
        return max;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}