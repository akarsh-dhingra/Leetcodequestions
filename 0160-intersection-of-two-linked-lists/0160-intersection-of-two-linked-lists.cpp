/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode*collisionpoint(ListNode *slow, ListNode *fast,int d){
    while(d!=0){
        d--;
        fast=fast->next;
    }
    while(slow!=fast){
       slow=slow->next;
       fast=fast->next; 
    }
return slow;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL) return NULL;
        ListNode*t1=headA;
        ListNode*t2=headB;
        int l1=0;
        int l2=0;
        while(t1){
            t1=t1->next;
            l1++;
        }
        while(t2){
            t2=t2->next;
            l2++;
        }
        t1=headA;
        t2=headB;
        if(l1<l2){
            return collisionpoint(t1,t2,l2-l1);
        }
        else{
            return collisionpoint(t2,t1,l1-l2);
        }
    }
};