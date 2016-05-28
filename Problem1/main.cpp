#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
static bool compare(int *i,int *j){
    return *i<*j;
}
class Solution{
public:

    vector<int> twoSum(vector<int> &nums,int target){
        multimap<int,int> map;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            map.insert(pair<int,int>(nums[i],i));
        }
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<j){
            int tmp=nums[i]+nums[j];
            if(tmp==target){
                if(nums[i]==nums[j]){
                    multimap<int,int>::iterator it=map.find(nums[i]);
                    result.push_back(it->second);
                    it++;
                    result.push_back(it->second);
                }else{
                    result.push_back(map.find(nums[i])->second);
                    result.push_back(map.find(nums[j])->second);
                }
                break;
            }else if(tmp>target){
                j--;
            }else{
                i++;
            }
        }
        return result;
    }
    vector<int> twoSum2(vector<int> &nums,int target){
        vector<int *> pnum;
        for(int i=0;i<nums.size();i++){
            pnum.push_back(&nums[i]);
        }
        sort(pnum.begin(),pnum.end(),compare);
        int s=0,t=nums.size()-1;
        vector<int> result;
        while(s<t){
            int sum=*pnum[s]+*pnum[t];
            if(sum==target){
                int idx1=pnum[s]-&nums[0];
                int idx2=pnum[t]-&nums[0];
                if(idx1>idx2) swap(idx1,idx2);
                result.push_back(idx1);
                result.push_back(idx2);
                return result;
            }else if(sum>target){
                t--;
            }else{
                s++;
            }
        }
        //the additional expression,if ignored,the code will not be passed by OJ.
        //well,if you must want to ignore it,it's OK.
        return result;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    vector<int> a;
    a.push_back(3);
    a.push_back(1);
    a.push_back(5);
    a.push_back(2);
    Solution ss;
    vector<int> b=ss.twoSum2(a,4);
    cout<<b[0]<<"-"<<b[1]<<endl;
    return 0;
}