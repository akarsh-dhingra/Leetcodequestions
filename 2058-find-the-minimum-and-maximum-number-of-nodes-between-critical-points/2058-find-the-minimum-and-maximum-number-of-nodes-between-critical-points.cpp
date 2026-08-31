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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Critical Point in the Linked List 
        // localMaxima 
        // localMinima
        // temp and head 
        // if length <=3
        vector<int>mpp;
        ListNode *temp=head->next;
        int indx=2;
        ListNode *prev=head;
        while(temp!=NULL && temp->next!=NULL){
            ListNode*next=temp->next;
            if((prev->val < temp->val && temp->val > next->val)||(               prev->val >temp->val && next->val > temp->val)){
                mpp.push_back(indx);
            }
            prev=temp;
            temp=next;
            indx++;
        }

        if(mpp.size()<=1) return {-1,-1};
        int miniD=INT_MAX;
        int maxiD=*max_element(mpp.begin(),mpp.end())-*min_element(mpp.begin(),mpp.end());
        sort(mpp.begin(),mpp.end());
        for(int i=1;i<mpp.size();i++){
            miniD=min(miniD,mpp[i]-mpp[i-1]);
        }   
        return {miniD,maxiD};
        
    }
};