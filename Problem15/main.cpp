#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum1(vector<int> &nums){
        multimap<int,int> mmap;
        vector<vector<int>> result;
        map<vector<int>,int> map;
        int index=0;
        if(nums.size()<=2) return result;
        for(int i=0;i<nums.size();i++) {
            mmap.insert(pair<int, int>(nums[i], i));
        }
        for(int i=0;i<nums.size()-2;i++){
            int t=0-nums[i];
            for(int j=i+1;j<nums.size()-1;j++){
                int tt=t-nums[j];
                pair<multimap<int,int>::iterator,multimap<int,int>::iterator> p=mmap.equal_range(tt);
                if(p.first==mmap.end())
                    continue;
                else{
                    for(multimap<int,int>::iterator it=p.first;it!=p.second;it++){
                        if((it->second)>j){
                            vector<int> tmp;
                            int a[3]={nums[i],nums[j],it->first};
                            sort(a,a+3);
                            tmp.push_back(a[0]);
                            tmp.push_back(a[1]);
                            tmp.push_back(a[2]);
                            if(map.find(tmp)==map.end()) {
                                map.insert(pair<vector<int>,int>(tmp,index));
                                result.push_back(tmp);
                                index++;
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
    vector<vector<int>> twoSum(vector<int> &src,int l,int r,int target){
        int i=l,j=r-1;
        vector<vector<int>> result;
        while(i<j){
            int tmp=src[i]+src[j];
            if(tmp==target){
                vector<int> tt;
                tt.push_back(src[i]);
                tt.push_back(src[j]);
                result.push_back(tt);
                i++,j--;
            }else if(tmp>target){
                j--;
            }else{
                i++;
            }
        }
        return result;
    }
    vector<vector<int>> threeSum2(vector<int> &nums){
        vector<vector<int>> result;
        if(nums.size()==0)
            return result;
        sort(nums.begin(),nums.end());
        map<vector<int>,int> map;
        for(int i=0;i<nums.size()-2 && nums[i]<=0;i++){
            vector<vector<int>> tmp=twoSum(nums,i+1,nums.size(),0-nums[i]);
            if(tmp.size()==0) continue;
            for(int j=0;j<tmp.size();j++){
                vector<int> tt=tmp[j];
                int a[3]={nums[i],tt[0],tt[1]};
                sort(a,a+3);
                vector<int> st;
                st.push_back(a[0]);
                st.push_back(a[1]);
                st.push_back(a[2]);
                if(map.find(tt)==map.end()){
                    map.insert(pair<vector<int>,int>(st,0));
                    result.push_back(st);
                }
            }
        }
        return result;
    }
    vector<vector<int>> threeSum3(vector<int> &nums){
        vector<vector<int>> result;
        if(nums.size()<=2) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2 && nums[i]<=0;i++){
            int tmp=0-nums[i];
            if(i>0 && i<nums.size()-2 && nums[i]==nums[i-1])
                continue;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int t=nums[j]+nums[k];
                if(t==tmp){
                    vector<int> s;
                    s.push_back(nums[i]);
                    s.push_back(nums[j]);
                    s.push_back(nums[k]);
                    result.push_back(s);
                    while((j<(nums.size())-1) && (nums[j]==nums[j+1]))
                        j++;
                    while((k>j) && (nums[k]==nums[k-1]))
                        k--;
                    j++,k--;
                }else if(t>tmp){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(-1);
    nums.push_back(1);
    nums.push_back(2);
//    multimap<int,int> map;
//    map.insert(pair<int,int>(-1,0));
//    map.insert(pair<int,int>(0,1));
//    map.insert(pair<int,int>(1,2));
//    map.insert(pair<int,int>(2,3));
//    map.insert(pair<int,int>(-1,4));
//    map.insert(pair<int,int>(-4,5));
//    multimap<int,int>::iterator it=map.find(-1);
//    pair<multimap<int,int>::iterator,multimap<int,int>::iterator> p=map.equal_range(3);
//    cout<<(p.first==map.end())<<endl;
//    for(multimap<int,int>::iterator it=p.first;it!=p.second;it++)
//        cout<<it->second<<endl;
//    cout<<"last:"<<(p.second)->second<<endl;
    Solution ss;
    vector<vector<int>> r=ss.threeSum3(nums);
    for(int i=0;i<r.size();i++){
        vector<int> t=r[i];
        for(int j=0;j<t.size();j++)
            cout<<t[j]<<",";
        cout<<endl;
    }
    cout << "Hello, World!" << endl;
    return 0;
}