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
    ListNode *reverseList(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode*temp=head;
        ListNode*agla=reverseList(temp->next);
        temp->next->next=temp;
        temp->next=NULL;
        return agla;
    }
    ListNode* swapNodes(ListNode* head, int k) {
     ListNode*x1=head;
     ListNode*temp=head;
     int cnt=1;
     while(cnt<k ){
        x1=x1->next;
        cnt++;
     }
     ListNode*reverseHead=reverseList(head);
     ListNode *x2=reverseHead;
     cnt=1;
     while(cnt<k ){
        x2=x2->next;
        cnt++;
     }
    reverseList(reverseHead);
    swap(x1->val,x2->val);
    return head;    
    }
};