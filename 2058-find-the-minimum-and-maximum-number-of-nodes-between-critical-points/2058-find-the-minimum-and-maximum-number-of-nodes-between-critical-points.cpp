/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

// Critical Point in the Linked List 
        // localMaxima 
        // localMinima
        // temp and head 
        // if length <=3

 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL|| head->next==NULL) return {-1,-1};
        ListNode *prev=head;
        ListNode *curr=head->next;
        int indx=1;
        int firstPosition=0;
        int prevPosition=0;
        int minDist=INT_MAX;
        while(curr->next!=NULL){
            ListNode *next=curr->next;
            if((prev->val < curr->val && curr->val > next->val)||(               prev->val >curr->val && next->val > curr->val)){
                if(prevPosition!=0){
                    minDist=min(minDist,indx-prevPosition);
                }
                if(firstPosition==0)firstPosition=indx;
                prevPosition=indx;
            }
            indx++;
            prev=curr;
            curr=next;
        }

        if(minDist==INT_MAX) return {-1,-1};
        else return {minDist,prevPosition-firstPosition};
    }
};