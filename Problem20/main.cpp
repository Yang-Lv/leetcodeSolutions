#include <iostream>
#include <stack>
#include <map>
using namespace std;

class Solution{
public:
        bool in(const char *s,int len,char c){
            for(int i=0;i<len;i++){
                if(c==s[i]){
                    return true;
                }
            }
            return false;
        }
        bool isValid(string s){
            char left[]={'(','[','{'};
            char right[]={')',']','}'};
            map<char,char> map;
            for(int i=0;i<3;i++){
                map[left[i]]=right[i];
            }
            stack<char> stack;
            int flag= false;
            int len=s.size();
            //boundary condition
            if(len==0) return true;
            if(len==1) return false;
            //for each element is s do :
            int i=1;
            stack.push('@');//'@作为守护字符'
            stack.push(s[0]);
            while(i<len){
                if(!in(right,3,s[i])){
                    stack.push(s[i]);
                }else{
                    if(map[stack.top()]!=s[i]){
                        return false;
                    }else{
                        stack.pop();
                    }
                }
                i++;
            }
            if(stack.top()=='@'){
                return true;
            }else{
                return false;
            }
        }
};

int main() {
    Solution s;
    cout<<s.isValid("()[]{}")<<endl;
    cout<<true<<endl;
    cout << "Hello, World!" << endl;
    return 0;
}