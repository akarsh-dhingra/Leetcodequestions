/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 We are given the numbers but all the numbers 
 are stored in the reverse order!!

 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // We are definitely needing a new Node 
        // that is a new Linked List 
        // During insertion bhi dummy node use hoga
        ListNode *dummy= new ListNode(-1);
        ListNode *curr=dummy;
        // to traverse in the list like we always do similar to a temp
        // -1-> ()-> ()
        ListNode *t1=l1;
        ListNode *t2=l2;
    // 1 2 3
    // 2 3 
        int carry=0;
        while(t1!=NULL || t2!=NULL){
            int currSum=carry;
            if(t1) currSum+=t1->val;
            if(t2) currSum+=t2->val;
            ListNode *nextNode=new ListNode(currSum%10);
            curr->next=nextNode;
            curr=curr->next;
            carry=currSum/10;
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }

        if(carry){
            ListNode *some=new ListNode(carry);
            curr->next=some;
        }

        return dummy->next;
    }
};