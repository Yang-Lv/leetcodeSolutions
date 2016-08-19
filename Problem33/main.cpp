#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    /* (递增块a)|(递增快b)
     * a的最小值比b的最大值要大(前提:原有序的序列是单调增的)
     * idea:
     * step1:通过二分查找到最小值的下标
     * step2:将整个序列看成是一个圆圈,而最小值的下标就是每个元素下标的bias.
     * */
    int search(vector<int> &nums,int target){
        int n=nums.size();
        if(n==0) return -1;
        int lf=0,rt=n-1;
        //find the smallest number's index in nums
        while(lf<rt){
            int mid=(lf+rt)/2;
            if(nums[mid]>nums[rt]) lf=mid+1;
            else rt=mid;
        }
        int idx=lf;
        cout<<"min:"<<idx<<endl;
        //binary search
        lf=0;rt=n-1;
        while(lf<=rt){
            int mid=(lf+rt)/2;
            int realmid=(mid+idx)%n;
            if(nums[realmid]==target) return realmid;
            if(nums[realmid]>target){
                rt=mid;
            }else{
                lf=mid;
            }
        }
        return -1;
    }
    int binarySearch(vector<int> &nums,int i,int j,int target){
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target) j=mid-1;
            else i=mid+1;
        }
        return -1;
    }
    int search2(vector<int> &nums,int target){
        int n=nums.size();
        if(n==0) return -1;
        int lf=0,rt=n-1;
        while(lf<=rt){
            int mid=(lf+rt)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>nums[mid+1]){
                //boundary:nums[mid]:max;nums[mid+1]:min
                if(target<nums[mid+1] || target>nums[mid]) return -1;
                //for left and right part,do binary search
                int t=binarySearch(nums,lf,mid-1,target);
                if(t!=-1) return t;
                else return binarySearch(nums,mid+1,rt,target);
            }else{
                //within,not boundary:judge the left or right part
                if(nums[mid]>nums[lf]){
                    //within left part
                    if(target>nums[mid] || target<nums[lf]) lf=mid+1;
                    else{
                        //surrly from lf to mid-1,the array is sorted.
                        int t=binarySearch(nums,lf,mid-1,target);
                        return t;
                    }
                }else{
                    //within right part
                    if(target>nums[rt] || target<nums[mid]) rt=mid-1;
                    else{
                        int t=binarySearch(nums,mid+1,rt,target);
                        return t;
                    }
                }
            }
        }
        return -1;
    }
};



int main() {
    return 0;
}