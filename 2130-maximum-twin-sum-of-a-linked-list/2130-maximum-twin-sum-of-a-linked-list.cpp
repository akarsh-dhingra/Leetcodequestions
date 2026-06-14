/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
Given the LL 
maximize twin+node at every time 
5->4->2->1 

 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>arr;
        ListNode *temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            int sum=arr[i]+arr[n-i-1];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};