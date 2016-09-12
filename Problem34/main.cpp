#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<int> searchRange(vector<int> &nums,int target){
        vector<int> res;
        int i=0,j=nums.size()-1;
        int start=-1,end=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                //i to mid and get start
                //i and j always out range,start and end always in range
                //so when i==start or j==end ,it means the loop overs
                start=mid;
                while(i<start){
                    int m1=(i+start)/2;
                    if(nums[m1]<target){
                        i=m1+1;
                    }else{
                        start=m1;
                    }
                }
                //mid to j and get end
                end=mid;
                while(end<j){
                    int m2=(end+j)/2;
                    m2+=end+j%2?1:0;
                    if(nums[m2]>target){
                        j=m2-1;
                    }else{
                        end=m2;
                    }
                }
                break;
            }else if(nums[mid]>target){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        res.push_back(start);
        res.push_back(end);
        return res;
    }
};
int main() {
    vector<int> nums,res;
    nums.push_back(2);
    nums.push_back(2);
    Solution s;
    res=s.searchRange(nums,2);
    for(auto i : res){
        cout<<i<<endl;
    }
    return 0;
}