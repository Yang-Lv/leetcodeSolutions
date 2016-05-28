#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};
class Solution{
public:
    ListNode *addTwoNumbers(ListNode *l1,ListNode *l2){
        int c=0;
        int flag= true;
        ListNode *head;
        ListNode *pre;
        while(l1 && l2){
            int num=l1->val+l2->val+c;
            if(num>=10){
                num-=10;
                c=1;
            }else{
                c=0;
            }
            ListNode *p=new ListNode(num);
            if(flag){
                head=p;
                pre=p;
                flag= false;
            }else{
                pre->next=p;
                pre=p;
            }
            l1=l1->next;
            l2=l2->next;
        }
        if(l1){
            while(l1){
                if(c==0){
                    pre->next=l1;
                    break;
                }
                int num=l1->val+c;
                if(num>=10){
                    num-=10;
                    c=1;
                }else{
                    c=0;
                }
                ListNode *p=new ListNode(num);
                pre->next=p;
                pre=p;
                l1=l1->next;
            }
        }
        if(l2){
            while(l2){
                if(c==0){
                    pre->next=l2;
                    break;
                }
                int num=l2->val+c;
                if(num>=10){
                    num-=10;
                    c=1;
                }else{
                    c=0;
                }
                ListNode *p=new ListNode(num);
                pre->next=p;
                pre=p;
                l2=l2->next;
            }
        }
        if(c!=0){
            ListNode *p=new ListNode(c);
            pre->next=p;
        }
        return head;
    }
};
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}