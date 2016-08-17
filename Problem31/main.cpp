#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    void swap(vector<int> &nums,int i,int j){
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }
    void reverse(vector<int> &nums,int i,int j){
        for(int l=i,r=j;l<r;l++,r--){
            int tmp=nums[l];
            nums[l]=nums[r];
            nums[r]=tmp;
        }
    }
    void nextPermutation(vector<int> &nums){
        int len=nums.size();
        if(len<=1) return ;
        int start=len-1,end=start-1;
        while(end>=0 && nums[start]<=nums[end]){
            start--;
            end--;
        }
        if(end<0){
            //reverse all array
            reverse(nums,0,len-1);
        }else{
            int a=nums[end],b;
            int idx=end+1;
            for(;idx<len && a<nums[idx];idx++);
            idx--;
            swap(nums,end,idx);
            //reverse from end+1 to len-1
            reverse(nums,end+1,len-1);
        }
    }
};
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}