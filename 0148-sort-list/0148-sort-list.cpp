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
    ListNode *mid(ListNode *head){
        ListNode *slow=head;
        ListNode *fast=head->next; // we want middle to stop at 1-> 2-> 3-> 4 that is at 2 
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *l1,ListNode *l2){
        ListNode *dummy =new ListNode(-1);
        ListNode *temp=dummy;

        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                temp->next=l1;
                temp=temp->next;
                l1=l1->next;
            }
            
            else {
                 temp->next=l2;
                temp=temp->next;
                l2=l2->next;
            }
        }
        while(l1){
                temp->next=l1;
                temp=temp->next;
                l1=l1->next;
        }
        while(l2){
                temp->next=l2;
                temp=temp->next;
                l2=l2->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *middle=mid(head);
        ListNode *leftHead=head;
        ListNode *rightHead=middle->next;
        middle->next=NULL;
        ListNode* leftHeadNew=sortList(leftHead);
        ListNode* rightHeadNew=sortList(rightHead);
        return merge(leftHeadNew,rightHeadNew);
    }
};