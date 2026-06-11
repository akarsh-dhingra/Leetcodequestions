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
 ListNode *getKthNode(ListNode *head,int k){
        ListNode*temp=head;
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode *reverse(ListNode*head){
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        ListNode*prevNode=NULL;

        while(temp!=NULL){
            ListNode*kthNode=getKthNode(temp,k);
            // we've to separate that k group 
            // from the entire linked list 
            if(kthNode==NULL){
                if(prevNode) prevNode->next=temp;
                break;
            }
            ListNode*nextNode=kthNode->next;
            kthNode->next=NULL;
            ListNode*newHead=reverse(temp);
            if(temp==head){
                    head = newHead;
            }
            else{
                prevNode->next = newHead;

            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;

    }
};