/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };


 So my strategy for checking if a linked list is palindrom or not 
//  is that I will draw analogy with an array in an array I keep two 
// pointers and keep comparing 

So will do similar here as well , But I cannot traverse backward at the tail 
But what If I Reverse the second half of the linkedlist that is from slow->next 
and then eventually start compa
 */

class Solution {
public:
    ListNode *reverse(ListNode *head){
        ListNode*prev=NULL;
        ListNode*curr=head;
        while(curr!=NULL){
            ListNode*nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    ListNode*findMid(ListNode *head){
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*mid=findMid(head);
        ListNode*second=reverse(mid->next);
        ListNode*first=head;
        
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