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
    int findLength(ListNode *head){
        ListNode *temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=findLength(headA);
        int l2=findLength(headB);
        ListNode*temp1=headA;
        ListNode*temp2=headB;
        if(l1<l2){
            int diff=l2-l1;
            while(diff!=0){
                temp2=temp2->next;
                diff--;
            }
        }
        else {
            int diff2=l1-l2;
            while(diff2!=0){
                temp1=temp1->next;
                diff2--;
            }
        }
        while(1){
            if(temp1==temp2){
                return temp1;
            }
            if(temp1!=NULL)temp1=temp1->next;
            if(temp2!=NULL)temp2=temp2->next;
        }
        return NULL;
    }
};