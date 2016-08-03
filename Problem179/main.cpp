#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool compare(string a,string b){
    int i=0;
    while(a[i] && b[i]){
        if(a[i]==b[i]) {
            i++;
            continue;
        }else{
            return a[i]>b[i];
        }
    }
    //special case:one string is anther string's prefix
    string c;
    if(a[i]){
        c=a.substr(i);
        return compare(c,b);
    }
    if(b[i]){
        c=b.substr(i);
        return compare(a,c);
    }
    //case:a==b
    return true;
}
class Solution{
public:
    string largestNumber(vector<int> &nums){
        string res;
        vector<string> s;
        stringstream ss;
        string t;
        int flag=0;
        //init
        for(auto num:nums){
            flag|=num;
            ss<<num;
            ss>>t;
            ss.clear();
            s.push_back(t);
        }
        //special case:all zeros
        if(flag==0){
            return "0";
        }
        //sort by desc
        sort(s.begin(),s.end(),compare);
        for(auto tt:s){
            ss<<tt;
            cout<<tt<<endl;
        }
        ss>>res;
        return res;
    }
};
int main() {
    cout << "Hello, World!" << endl;
    int a[]={0,0,0,0,0,0,0};
    vector<int> nums(a,a+sizeof(a)/sizeof(int));
    Solution s;
    string res=s.largestNumber(nums);
    cout<<res<<endl;
//    vector<string> s;
//    stringstream ss;
//    string t;
//    //init
//    for(auto num:nums){
//        ss<<num;
//        ss>>t;
//        ss.clear();
//        s.push_back(t);
//    }
//    //sort
//    sort(s.begin(),s.end());
//    for(auto tt:s){
//        cout<<tt<<endl;
//    }
    return 0;
}