#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    /* 双指针并行
     * */
    int removeElement(vector<int> &nums,int val){
        int i=0,ni=0,len;
        len=nums.size();
        while(i<len){
            if(nums[i]!=val){
                nums[ni]=nums[i];
                ni++;
            }
            i++;
        }
        return ni;
    }
};
int removeElementByC(int *nums,int numsSize,int val){
    int i=0,ni=0;
    while(i<numsSize){
        if(nums[i]!=val){
            if(ni!=i){
                nums[ni]=nums[i];
            }
            ni++;
        }
        i++;
    }
    return ni;
}
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}