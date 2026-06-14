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
    ListNode* convertArrToLL(vector<int>&arr){
            if(arr.empty()) return NULL;

        ListNode *head=new ListNode(arr[0]);
        ListNode *temp=head;
        for(int i=1;i<arr.size();i++){
            ListNode*curr=new ListNode(arr[i]);
            temp->next=curr;
            temp=temp->next;
        }
        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Merge two sorted lists 

        vector<int>arr;
        ListNode *temp=list1;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }

        temp=list2;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }        
        sort(arr.begin(),arr.end());

        ListNode *ans=convertArrToLL(arr);
        return ans;
    }
};