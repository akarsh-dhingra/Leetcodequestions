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
int cntofll(ListNode*head){
    int cnt=0;
    ListNode*temp=head;
    while(temp!=nullptr){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
    ListNode* middleNode(ListNode* head) {
        if(head==NULL|| head->next==nullptr) return head;
        ListNode*temp=head;
        int midnode=cntofll(head)/2 +1;
        while(temp!=NULL){
            temp=temp->next;
            midnode--;
            if(midnode==1){
                break;
            }
        }
           return temp;
    }
};