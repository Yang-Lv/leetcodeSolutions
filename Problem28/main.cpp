#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    /* BF:brute force
     * */
    int strStrByBF(string haystack,string needle){
        int i=0,j=0;
        while(haystack[i]){
            if(needle[j]){
                if(haystack[i]=needle[j]){
                    i++;j++;
                }else{
                    i=i-j+1;j=0;
                }
            }else{
                return i-j;
            }
        }
        if(needle[j]){
            return -1;
        }else{
            return i-j;
        }
    }
};

int main() {

    return 0;
}