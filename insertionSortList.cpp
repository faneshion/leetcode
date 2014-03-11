
#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode * insertionListNode(ListNode* head);
void print(ListNode* head);

int main(void)
{
    ListNode head(3);
    ListNode l1(2);
    ListNode l2(4);
    head.next = &l1;
    l1.next = &l2;
    print(&head);
    cout<<endl;
    print(insertionListNode(&head));
    cout<<endl;

    return 1;
}
ListNode* insertionListNode(ListNode* head){
    if(!head || !head->next)
        return head;
    ListNode* last = head->next;
    while(last->next)
        last = last->next;
    ListNode *p1,*p2;
    p1 = p2 = NULL;
    while(head!=last){
        p2 = p1 = head;
        while(p2->next !=last)
            p2 = p2->next;
        if(p1 == p2 && p1->val <=p2->next->val){
            last = p1;
            return last;
        }else if(p1 == p2){
            while(p2->next && p2->next->val <= p1->val)
                p2=p2->next;
            p1->next = p2->next;
            p2->next = p1;
            return last;
        }
        else{
            while(p2->next){
                if(p1->val <=p2->next->val){
                    head = p1->next;
                    p1->next = p2->next;
                    p2->next = p1;
                    last = p1;
                    break;
                }else
                    p2 = p2->next;
            }
            if(!p2->next){
                head = p1->next;
                p1->next = p2->next;
                p2->next = p1;
            }
        }
    }
    return last;
}

void print(ListNode* head){
    ListNode *tmp = head;
    while(tmp){
        cout<<tmp->val<<"\t";
        tmp = tmp->next;
    }
}
