
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
    ListNode* currpre = head;
    ListNode *curr = head->next;
    while(curr){
        ListNode *pre,*p1;
        pre = p1 = head;
        if(curr->val < p1->val){
            currpre->next = curr->next;
            head = curr;
            head->next = p1;
            curr = currpre->next;
            continue;
        }else{
            p1 = p1->next;
            while(p1!=curr && curr->val > p1->val){
                p1 = p1->next;
                pre = pre->next;
            }
            if(p1 == curr){
                currpre = curr;
                curr = curr->next;
            }else{
                currpre->next = curr->next;
                curr->next = pre->next;
                pre->next = curr;
                curr = currpre->next;
            }
        }
    }
    return head;
}

void print(ListNode* head){
    ListNode *tmp = head;
    while(tmp){
        cout<<tmp->val<<"\t";
        tmp = tmp->next;
    }
}
