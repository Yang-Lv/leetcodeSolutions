#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    double findKth(vector<int> &nums1,int s1,int len1,vector<int> &nums2,int s2,int len2,int k){
        if(len1==0){
            return nums2[s2+k-1];
        }
        if(len2==0){
            return nums1[s1+k-1];
        }
        if(k==1){
            return nums1[s1]>nums2[s2]?nums2[s2]:nums1[s1];
        }
        int a,b;
        if(len1>len2){
            if(len2>=k/2){
                a=k-k/2;
                b=k/2;
            }else{
                b=len2;
                a=k-b;
            }
        }else{
            if(len1>=k/2){
                a=k/2;
                b=k-k/2;
            }else{
                a=len1;
                b=k-a;
            }
        }
        if(nums1[s1+a-1]==nums2[s2+b-1]){
            return nums1[s1+a-1];
        }else if(nums1[s1+a-1]>nums2[s2+b-1]){
            return findKth(nums1,s1,len1,nums2,s2+b,len2-b,k-b);
        }else{
            return findKth(nums1,s1+a,len1-a,nums2,s2,len2,k-a);
        }

    }
    double findMedianSortedArrays(vector<int> &nums1,vector<int> &nums2){
        //require:O(log(n+m))
        //len(nums1)=m,len(nums2)=n
        //binary search
        int m=nums1.size(),n=nums2.size();
        if((m+n)%2==1){
            return findKth(nums1,0,m,nums2,0,n,(m+n)/2+1);
        }else{
            return (findKth(nums1,0,m,nums2,0,n,(m+n)/2+1)+findKth(nums1,0,m,nums2,0,n,(m+n)/2))/2;
        }
    }
};

int main() {
    cout << "Hello, World!" << endl;
    vector<int> n1,n2;
//    n1.push_back(1);
//    n1.push_back(2);
//    n1.push_back(3);
    n2.push_back(1);
//    n2.push_back(3);
//    n2.push_back(4);
    Solution ss;
    cout<<ss.findMedianSortedArrays(n1,n2)<<endl;
    return 0;
}