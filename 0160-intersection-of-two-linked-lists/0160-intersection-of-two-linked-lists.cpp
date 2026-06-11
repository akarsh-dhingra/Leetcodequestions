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
    ListNode *collisionPoint(ListNode *t1, ListNode *t2,int len){
     while(len!=0){
        len--;
        t2=t2->next;
     }
     while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
     }
     return t1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode*t1=headA;
       ListNode*t2=headB;
        int n1=0;
        int n2=0;
       while(t1!=NULL){
            n1++;
            t1=t1->next;
       }
       while(t2!=NULL){
            n2++;
            t2=t2->next;
       }

       if(n1<n2){
        return collisionPoint(headA,headB,n2-n1);
       }
       else{
        return collisionPoint(headB,headA,n1-n2);
       }
    }
};