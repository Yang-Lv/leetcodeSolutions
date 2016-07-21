#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};
class Solution{
public:
    ListNode *mergeLists(ListNode *l1,ListNode *l2){
        ListNode *res,*current;
        //special case
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        res=current=NULL;
        //common case
        while(l1 && l2){
            ListNode *tmp;
            if(l1->val<=l2->val){
                tmp=l1;
                l1=l1->next;
            }else{
                tmp=l2;
                l2=l2->next;
            }
            tmp->next=NULL;
            if(current==NULL){
                res=current=tmp;
            }else{
                current->next=tmp;
                current=tmp;
            }
        }
        if(l1){
            current->next=l1;
        }
        if(l2){
            current->next=l2;
        }
        l1=NULL;
        l2=NULL;
        return res;
    }
    ListNode *mergeLists2(ListNode *l1,ListNode *l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val<=l2->val){
            l1->next=mergeLists2(l1->next,l2);
            return l1;
        }
        if(l2->val<l1->val){
            l2->next=mergeLists2(l1,l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode*> &lists){
        ListNode *res=NULL;
        int len=lists.size();
        //boundary condition
        if(len==0) return res;
        if(len==1) return lists[0];
        res=mergeLists(lists[0],lists[1]);
        //common case
        for(int i=2;i<lists.size();i++){
            res=mergeLists(lists[i],res);
        }
        return res;
    }

    ListNode *divideBy2(vector<ListNode *> &lists,int lf,int rt){
        ListNode *res;
        if(lf==rt) return lists[lf];
        int mid=(lf+rt)/2;
        ListNode *left=divideBy2(lists,lf,mid);
        ListNode *right=divideBy2(lists,mid+1,rt);
        return mergeLists(left,right);
    }
    ListNode *mergeKLists2(vector<ListNode*> &lists){
        //recursive method
        ListNode *res=NULL;
        int i=0,j=lists.size()-1,len=lists.size();
        //special case
        if(len==0) return res;
        //common case
        return divideBy2(lists,i,j);
    }
};

int main() {
    cout << "Hello, World!" << endl;
    ListNode *p=new ListNode(2);
    ListNode *p1=new ListNode(3);
    ListNode *p2=new ListNode(4);
    p->next=p1;
    p1->next=p2;
    ListNode *q=new ListNode(1);
    ListNode *q1=new ListNode(5);
    q->next=q1;
    vector<ListNode *> lists;
    lists.push_back(p);
    lists.push_back(q);
    Solution s;
    ListNode *res=s.mergeKLists2(lists);
    cout<<res->val<<endl;
    return 0;
}