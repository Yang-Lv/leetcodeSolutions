#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int threeSumClosest(vector<int> &nums,int target){
        int result=0;
        int minresult=0;
        int pre_dts=INT32_MAX;
        sort(nums.begin(),nums.end());
        if(nums.size()==3){
            return nums[0]+nums[1]+nums[2];
        }
        int i;
        for(i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int t=target-nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int tt=nums[j]+nums[k];
                pre_dts=tt;
                if(tt>t){
                    k--;
                }else if(tt<t){
                    j++;
                }else{
                    return target;
                }
            }
            if(pre_dts>t){
                k++;
            }else{
                j--;
            }
            if(j-1<1){
                int a=nums[j]+nums[k+1];
                result=abs(t-pre_dts)>abs(t-a)?a:pre_dts;
                result+=nums[i];
            }else if(k+1>=nums.size()){
                int a=nums[j-1]+nums[k];
                result=abs(t-pre_dts)>abs(t-a)?a:pre_dts;
                result+=nums[i];
            }else{
                int a=nums[j]+nums[k+1];
                int b=nums[j-1]+nums[k];
                int tmp=abs(t-pre_dts)>abs(t-a)?a:pre_dts;
                result=abs(t-tmp)>abs(t-b)?b:tmp;
                result+=nums[i];
            }
            if(i==0){
                minresult=result;
            }else{
                if(abs(result-target)<abs(minresult-target)){
                    minresult=result;
                }
            }

        }
        return minresult;
    }
};

int main() {
    vector<int> src;
    src.push_back(-3);
    src.push_back(-2);
    src.push_back(-5);
    src.push_back(3);
    src.push_back(-4);
    int target=-1;
    Solution ss;
    cout<<ss.threeSumClosest(src,target)<<endl;
    return 0;
}