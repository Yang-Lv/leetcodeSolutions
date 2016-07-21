#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
    ListNode *swapPairs(ListNode *head){
        ListNode *first,*second,*h,*pre;
        if(!head) return head;
        h=NULL;pre=NULL;
        while(head && head->next){
            first=head;
            head=head->next;
            second=head;
            head=head->next;
            first->next=NULL;
            second->next=first;
            if(pre==NULL){
                h=pre=second;
            }else{
                pre->next=second;
            }
            pre=first;
        }
        if(head){
           if(pre==NULL){
               h=head;
           }else{
               pre->next=head;
           }
        }
        return h;
    }
};
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}