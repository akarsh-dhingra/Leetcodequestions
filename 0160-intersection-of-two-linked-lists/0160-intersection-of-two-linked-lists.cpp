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
    ListNode *collisionPoint(ListNode *slow, ListNode *fast,int d){
        while(d--){
            fast=fast->next;
        }
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL) return headA;

        ListNode *tempA=headA;
        ListNode *tempB=headB;
        int l1=0;
        int l2=0;
        while(tempA!=NULL){
            tempA=tempA->next;
            l1++;
        }
        while(tempB!=NULL){
            tempB=tempB->next;
            l2++;
        }
        tempA=headA;
        tempB=headB;

        if(l1<l2){
            return collisionPoint(tempA,tempB,l2-l1);
        }
        else{
            return collisionPoint(tempB,tempA,l1-l2);
        }
    }
};