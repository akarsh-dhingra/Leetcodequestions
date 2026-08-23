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
    ListNode *findMid(ListNode*start){
        if(start==NULL || start->next==NULL) return start;
        ListNode *slow=start;
        ListNode *fast=start;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }   
        return slow;
    }
    ListNode *reverseList(ListNode *start){
        if(start==NULL || start->next==NULL) return start;
        ListNode *temp=start;
        ListNode *agla=reverseList(temp->next);
        temp->next->next=temp;
        temp->next=NULL;
        return agla;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*start=head;
        ListNode*mid=findMid(start);
        ListNode*end=reverseList(mid->next);
        while(end!=NULL){
            if(start->val==end->val){
                start=start->next;
                end=end->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};