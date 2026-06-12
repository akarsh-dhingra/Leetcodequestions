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
    ListNode* findMid(ListNode* head){
        ListNode*slow=head;
        ListNode*fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode*curr=head;
        ListNode*prev=NULL;

        while(curr!=NULL){
            ListNode*nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
    //    Find the middle of the linked list 
    //  reverse the section and compare it with the first
    ListNode*mid=findMid(head);
    // Now reverse 
    ListNode*newHead=reverse(mid->next);
    ListNode*first=head;
    ListNode*second=newHead;

    while(second!=NULL){
        if(first->val!=second->val){
            return false;
        }
        first=first->next;
        second=second->next;
    }
    return true;
    }
};