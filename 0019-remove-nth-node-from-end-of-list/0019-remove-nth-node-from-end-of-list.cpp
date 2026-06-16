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
    int lengthofll(ListNode*head){
        ListNode *temp=head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // calculate Length of LL
        // find L-n=k
        // if(l-n==l) for n=0
        if(head->next==NULL || head==NULL) return NULL;
        int len=lengthofll(head);
        int nodeNo=len-n;
        if(nodeNo==0){
            return head->next;
        }
        ListNode *temp=head;
        ListNode *prev=NULL;
        while(temp!=NULL){
            prev=temp;
            temp=temp->next;
            nodeNo--;
            if(nodeNo==0) break;
        }
        prev->next=temp->next;
        temp->next=NULL;
        return head;
    }
};