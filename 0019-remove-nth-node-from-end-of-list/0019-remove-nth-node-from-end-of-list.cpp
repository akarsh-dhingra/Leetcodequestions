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
//  ListNode*deletetail(ListNode*head){
//     // think about the edge case very clearly

//      if(head==NULL||head->next==nullptr){
//         return head;
//     }
//     ListNode*temp=head;
//     while(temp->next->next!=NULL){
//         temp=temp->next;
//     }
     
//     delete temp->next;
//     temp->next=nullptr;
//     return head;
//  }
// int lengthofll(ListNode*head){
// int cnt=0;
// ListNode*temp=head;
// while(temp){
//     cnt++;
//     temp=temp->next;
// }
// return cnt; 
// }
//     ListNode* reverseList(ListNode* head) {
//         ListNode*temp=head;
//         ListNode*prev=NULL;
//         while(temp!=NULL){
//            ListNode*front=temp->next;
//             temp->next=prev;
//             prev=temp;
//             temp=front;
//         }
//         return prev;
//     }
//     ListNode*deletenethele(ListNode*newhead,int n){
//       if(newhead==NULL||newhead->next==NULL){
//         return newhead;
//       }
//       if(n==1){
//         ListNode*temp=newhead;
//         newhead=newhead->next;
//         temp->next=NULL;
//         delete(temp);
//         return newhead;
//       }
//       else if(n==lengthofll(newhead)){
//       deletetail(newhead);
//       }
//       else{
//     ListNode*temp=newhead;
//     ListNode*prev=NULL;
//     int cnt=0;
//     while(temp){
//       cnt++;
//       if(cnt==n){
//       prev->next=prev->next->next;
//       delete(temp);
//       break;
//       }
//       prev=temp;
//       temp=temp->next;
//     }
//       }
//       return newhead;
//     }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL||head->next==NULL){
            delete(head);
            return NULL;
        }
       ListNode*temp=head;
       int cnt=0;
       while(temp){
        temp=temp->next;
        cnt++;
       }
       temp=head;
       int res=cnt-n;
        if(cnt==n){
        ListNode*newhead=head->next;
            delete(head);
            return newhead;
       }
       temp=head;
       while(temp){
        res--;
        if(res==0){
            break;
        }
        temp=temp->next;
       }
        ListNode*delnode=temp->next;
        temp->next=temp->next->next;
         delete(delnode);
        return head;
    }
};