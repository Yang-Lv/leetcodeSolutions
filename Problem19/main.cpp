#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* removeNthNodeFromEnd(ListNode *head,int n){
        //use to pointer i and j,where j is n steps before i
        //Then pointer i and j march step by step ,when j arrives at the last node,i point to Nth node from end.
        ListNode *i,*j,*pre_i=NULL;//pre_i record the previous node of i
        i=j=head->next;
        for(int k=0;k<n;k++){
            j=j->next;
        }
        while(j){
            pre_i=i;
            i=i->next;
            j=j->next;
        }
        if(pre_i==NULL){
            head=i->next;
        }else{
            pre_i->next=i->next;
        }
        delete(i);
        i=NULL;
        return head;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}