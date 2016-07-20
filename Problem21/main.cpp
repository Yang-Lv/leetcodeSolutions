#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};
class Solution{
public:
    ListNode *mergeTwoLists(ListNode *l1,ListNode *l2){
        ListNode *l3,*pre;
        //boundary condition
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        //l1 and l2 both not empty
        l3=NULL;
        pre=NULL;
        while(l2 && l1){
            if(l1->val<=l2->val){
                ListNode *tmp=l1;
                l1=l1->next;
                if(l3==NULL){
                    l3=tmp;
                    pre=l3;
                }else{
                    pre->next=tmp;
                    pre=tmp;
                }
            } else if(l1->val>l2->val){
                ListNode *tmp=l2;
                l2=l2->next;
                if(l3==NULL){
                    l3=tmp;
                    pre=l3;
                }else{
                    pre->next=tmp;
                    pre=tmp;
                }
            }
        }
        if(l1){
            pre->next=l1;
        }
        if(l2){
            pre->next=l2;
        }
        return l3;
    }
};
int main() {

    cout << "Hello, World!" << endl;
    return 0;
}