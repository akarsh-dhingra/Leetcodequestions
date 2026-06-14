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
    // ListNode* convertArrToLL(vector<int>&arr){
    //     if(arr.empty()) return NULL;
    //     ListNode *head=new ListNode(arr[0]);
    //     ListNode *temp=head;
    //     for(int i=1;i<arr.size();i++){
    //         ListNode*curr=new ListNode(arr[i]);
    //         temp->next=curr;
    //         temp=temp->next;
    //     }
    //     return head;
    // }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*dummy=new ListNode(-1);
        ListNode*curr=dummy;
        ListNode *t1=list1;
        ListNode *t2=list2;

        while(t1!=NULL && t2!=NULL){
            if(t1->val<=t2->val){
                ListNode*newNode=new ListNode(t1->val);
                curr->next=newNode;
                curr=curr->next;
                t1=t1->next;
            }
            else {
                ListNode*newNode=new ListNode(t2->val);
                curr->next=newNode;
                curr=curr->next;
                t2=t2->next;
            }
            
        }
        while(t1!=NULL){
            ListNode*newNode=new ListNode(t1->val);
                curr->next=newNode;
                curr=curr->next;
                 t1=t1->next;
        }
        while(t2!=NULL){
                ListNode*newNode=new ListNode(t2->val);
                curr->next=newNode;
                curr=curr->next;
                 t2=t2->next;
        }
        return dummy->next;
    }
};