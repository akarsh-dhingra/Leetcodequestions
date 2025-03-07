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

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        int length=0;
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            length++;
        }
        ListNode*tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        temp=head;
        if(k%length==0) return head;
            k=k%length;
            int rot=length-k;
            while(rot!=1){
                temp=temp->next;
                rot--;
            }
            tail->next=head;
            head=temp->next;
            temp->next=NULL;
            return head;
    }
};