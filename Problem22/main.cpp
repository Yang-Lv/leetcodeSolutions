#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
    vector<string> generateParenthesis(int n){
        vector<string> result;
        vector<vector<string>> pre;
        map<string,string> map; //用来排除重复项
        if(n==0) return result;
        vector<string> t;
        t.push_back("()");
        pre.push_back(t);
        int count=0;
        for(int i=2;i<=n;i++){
            vector<string> tmp;
            for(int j=0;j<i;j++){
                if(j==0){
                    for(string tt:pre[i-2-j]){
                        tt.insert(0,"(");
                        tt.insert(tt.length(),")");
                        if(map.find(tt)==map.end()){
                            map[tt]=tt;
                            tmp.push_back(tt);
                        }else{count++;}
                    }
                }else{
                    vector<string> left=pre[j-1];
                    vector<string> right=pre[i-j-1];
                    for(string tl:left){
                        for(string tr:right){
                            string ss=tl+tr;
                            if(map.find(ss)==map.end()){
                                map[ss]=ss;
                                tmp.push_back(ss);
                            }else{count++;}
                        }
                    }
                }
            }
            pre.push_back(tmp);
            map.clear();
        }
        result=pre[n-1];
        cout<<"重复数:"<<count<<endl;
        return result;
    }
    void find(vector<string> &result,int i,int left,int right,string r,const int len){
        if(i==len){
            result.push_back(r);
            return ;
        }
        //"("已经满了
        if(left==len/2){
            r.push_back(')');
            find(result,i+1,left,right+1,r,len);
        }else if(left>right){
            string t=r;
            //增加"("
            r.push_back('(');
            find(result,i+1,left+1,right,r,len);
            //增加")"
            t.push_back(')');
            find(result,i+1,left,right+1,t,len);
        }else if(left==right){
            //只能增加"("
            r.push_back('(');
            find(result,i+1,left+1,right,r,len);
        }else{
            exit(-1);
        }
    }
    vector<string> generateParenthesis2(int n){
        //recursive method
        vector<string> result;
        if(n==0) return result;
        string r="";
        int i=0;
        int leftnum=0,rightnum=0;
        r.push_back('(');
        leftnum++;
        i++;
        find(result,i,leftnum,rightnum,r,2*n);
        return result;
    }
};
int main() {
    Solution s;
    vector<string> r=s.generateParenthesis2(4);
    cout<<r.size()<<endl;
    for(string i:r){
        cout<<i<<endl;
    }
    return 0;
}