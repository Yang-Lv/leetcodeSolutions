#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
private:
    bool isTrue(string s,multimap<string,int> p,bool *visited,int wordLen,int num){
        pair<multimap<string,int>::iterator,multimap<string,int>::iterator> ret;
        multimap<string,int>::iterator it;
        for(int i=0;i<num;i++){
            string word=s.substr(i*wordLen,wordLen);
            ret=p.equal_range(word);
            //不存在该单词
            if(ret.first==ret.second) return false;
            bool flag=false;
            it=ret.first;
            while(it!=ret.second){
                if(!visited[it->second]){
                    visited[it->second]=true;
                    flag=true;
                    break;
                }else{
                    it++;
                }
            }
            if(!flag) return false;
        }
        return true;
    }
public:
    //my method--naive
    vector<int> findSubstring(string s,vector<string> &words){
        vector<int> res;
        int num=words.size(),wordLen,sLen;
        multimap<string,int> p;
        //case1:
        if(!num) return res;
        //case2:
        wordLen=words[0].length();
        sLen=s.length();
        if(num*wordLen>sLen) return res;
        //common case:
        //init words map:p
        bool *visited=new bool[num];
        for(int i=0;i<num;i++){
            p.insert(pair<string,int>(words[i],i));
        }
        for(int i=0;i<wordLen;i++){
            int p2=i;
            while((sLen-p2)>=wordLen*num){
                for(int j=0;j<num;j++) visited[j]=false;
                string sub=s.substr(p2,wordLen*num);
                if(isTrue(sub,p,visited,wordLen,num)){
                    res.push_back(p2);
                }
                p2+=wordLen;
            }
        }
        return res;
    }

    //faster method
    //time complexity:O(N) with two map
    vector<int> findSubstring2(string s,vector<string> &words){
        vector<int> res;
        int num=words.size(),wordLen,sLen;
        //case1:
        if(!num) return res;
        sLen=s.size();
        wordLen=words[0].size();
        //case2:
        if(num*wordLen>sLen) return res;
        //common case:
        map<string,int> p;
        int i=0;
        for(auto word:words) p[word]++;
        while(i<wordLen){
            map<string,int> q;
            int start=i,cur=num;
            while((sLen-start)>=cur*wordLen){
                string sub=s.substr(start,wordLen);
                if(p.find(sub)==p.end()){
                    q.clear();
                    cur=num;
                }else if(q[sub]==p[sub]){
                    //当前的单词已经达到出现的最高次数时:
                    //回退:从第一个单词开始,直到出现当前单词为止,修改每个单词的出现次数
                    //相当于抛弃了第一次出现当前单词之前(包含当前单词)的所有单词
                    //例如:当前单词是:"cur",    ....curbar...cur..  -->>bar...cur..
                    for(int j=start-(num-cur)*wordLen;s.substr(j,wordLen)!=sub;j+=wordLen){
                        q[s.substr(j,wordLen)]--;
                        cur++;
                    }
                }else{
                    q[sub]++;
                    cur--;
                    if(cur==0){
                        res.push_back(start-wordLen*(num-1));
                        //抛弃第一个单词,并从第二个单词开始
                        //例如:第一个单词是:cur    curbar....   -->> bar...
                        q[s.substr(start-wordLen*(num-1),wordLen)]--;
                        cur++;
                    }
                }
                start+=wordLen;
            }
            i++;
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<string> words;
    vector<int> res;
    words.push_back("foo");
    words.push_back("bar");
    res=s.findSubstring2("barfoothefoobarman",words);
    for(auto i:res){
        cout<<i<<endl;
    }
    return 0;
}