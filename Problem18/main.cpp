#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int> &nums,int target,int start){
        vector<vector<int>> res;
        int len=nums.size();
        if(len<3)
            return res;
        for(int i=0;i<len-2;i++){
            if(nums[i]>=0 && nums[i]>target)
                break;
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            int t=target-nums[i];
            int j=i+1,k=len-1;
            while(j<k) {
                int tmp = nums[j] + nums[k];
                if (tmp == t) {
                    vector<int> r;
                    r.push_back(start);
                    r.push_back(nums[i]);
                    r.push_back(nums[j]);
                    r.push_back(nums[k]);
                    res.push_back(r);
                    int tt = nums[j];
                    j++;
                    while (j < k) {
                        if (nums[j] == tt) {
                            j++;
                        } else {
                            break;
                        }
                    }
                } else if (tmp > t) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int> &nums,int target){
        vector<vector<int>> res;
        int len=nums.size();
        if(len<=3)
            return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-3;i++){
            if(nums[i]>=0 && nums[i]>target)
                break;
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            int t=target-nums[i];
            vector<int> tnums(nums.begin()+i+1,nums.end());
            vector<vector<int>> tmpRes=threeSum(tnums,t,nums[i]);
            if(tmpRes.size()==0)
                continue;
            else{
                for(int i=0;i<tmpRes.size();i++){
                    res.push_back(tmpRes[i]);
                }
            }
        }
        return res;
    }
};
void print(const int &a){
    cout<<a<<"  ";
}
bool compare(int *i,int *j){
    return *i<*j;
}
int main() {
//    cout << "Hello, World!" << endl;
//    vector<int> a;
//    a.push_back(3);
//    a.push_back(1);
//    a.push_back(2);
//    vector<int *> b;
//    b.push_back(&a[0]);
//    b.push_back(&a[1]);
//    b.push_back(&a[2]);
//    sort(b.begin(),b.end(),compare);
//    for(int i=0;i<3;i++)
//        cout<<*b[i]<<"  ";
//    vector<int> c(a.begin()+1,a.end());
//    for_each(c.begin(),c.end(),print);
    Solution s;
    int arr[]={1,-2,-5,-4,-3,3,3,5};
    int target=-11;
    vector<int> nums(arr,arr+8);
    vector<vector<int>> t=s.fourSum(nums,target);
    for(int i=0;i<t.size();i++){
        for_each(t[i].begin(),t[i].end(),print);
        cout<<endl;
    }
    return 0;
}