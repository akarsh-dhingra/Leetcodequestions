/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
   // place temp at head 
        // figure out the kth node 
        // reverse the section from head to kthNodde 
        // if temp==head head =kthNode (i.e. it is the start)
        // we also have to remember the lastNode in the preivous group which was our temp
        // prevNode->next=to the next kth nodde
     // find collision Point i.e. check if a loop exist or not 
        // If exist then simply yk place a pointer at start and the collision Point and keep iterating if you find a common one then yes that is the fucking starting point
 */
class Solution {
public:
    ListNode *findCollision(ListNode *head){
        // if(head==NULL || head->next==NULL) return head;
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return slow;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=findCollision(head);
        if(slow==NULL) return NULL;
        ListNode *fast=head;

        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};