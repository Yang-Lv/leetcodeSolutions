#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution{
public:
    ListNode *reverseKGroup(ListNode *head,int k){
        ListNode *start,*end,*res,*cur,*cur1;//*cur表示res的指针当前位置
        int i=0;
        start=end=head;
        res=cur=cur1=NULL;
        while(end){
            i=0;
            while(end && i<k){
                end=end->next;
                i++;
            }
            if(i<k){
                if(!res){
                    res=head;
                }else{
                    cur->next=start;
                }
                return res;
            }else{
                //reverse the k nodes
                ListNode *tmp=NULL;
                while(start!=end){
                    //remove the node from the list
                    ListNode *p=start;
                    start=start->next;
                    //前插入
                    p->next=NULL;
                    if(!tmp){
                        cur1=tmp=p;//同时更新cur指针
                    }else{
                        p->next=tmp;
                        tmp=p;
                    }
                }
                if(!res){
                    res=tmp;
                }else{
                    cur->next=tmp;
                }
                cur=cur1;
            }
        }
        return res;
    }
};
int main() {
    ListNode *p1,*p2,*p3,*p4,*p5,*p6,*p7;
    p1=new ListNode(1);
    p2=new ListNode(2);
    p3=new ListNode(3);
    p4=new ListNode(4);
    p5=new ListNode(5);
    p6=new ListNode(6);
    p7=new ListNode(7);
    p1->next=p2;
    p2->next=p3;
    p3->next=p4;
    p4->next=p5;
    p5->next=p6;
    p6->next=p7;
    Solution s;
    ListNode *res=s.reverseKGroup(p1,3);
    while(res){
        cout<<res->val<<"  ";
        res=res->next;
    }
    cout<<endl;
    return 0;
}