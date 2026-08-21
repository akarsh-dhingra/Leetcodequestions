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
    ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode*temp=head;
        ListNode*agle=reverseList(temp->next);
        temp->next->next=temp;
        temp->next=NULL;
        return agle;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*x1=head;
        int cnt=1;
        while(cnt<k){
            x1=x1->next;
            cnt++;
        }
        ListNode*x2=reverseList(head);
        ListNode*newHead=x2;
        cnt=1;
        while(cnt<k){
            x2=x2->next;
            cnt++;
        }
        reverseList(newHead);
        swap(x1->val,x2->val);
        return head;
    }
};