/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp!=NULL){
           ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* kthnode(ListNode* head, int k){
        ListNode* temp=head;
       k-=1;
    while(temp!=NULL&&k>0){
        temp=temp->next;
        k--;
    }
    return temp;
    }
ListNode* reverseKGroup(ListNode* head, int k) {
ListNode*temp=head;
ListNode*prevlast=NULL;
while(temp!=NULL){
    ListNode*kthLastNode=kthnode(temp,k);// this will return the kth node of every k group of elements
    if(kthLastNode==NULL){
        if(prevlast){
            prevlast->next=temp;
        }
        break;
    }
    ListNode*nextNode=kthLastNode->next; // have to remember the nextnode because this will help later to join.
    kthLastNode->next=NULL;
    reverseList(temp);
    if(temp==head){
        head=kthLastNode;
    }
    else{
        prevlast->next=kthLastNode;
    }
    prevlast=temp;
    temp=nextNode;
}
return head;
    }
};