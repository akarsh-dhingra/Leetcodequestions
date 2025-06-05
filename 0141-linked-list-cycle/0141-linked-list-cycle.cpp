/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         // hashing
        unordered_map<ListNode*,bool>mapping;
        ListNode*temp=head;
        while(temp){
            if(mapping.find(temp)!=mapping.end()){
                return true;
            }
            else{
                mapping[temp]=true;
            }
            temp=temp->next;
        }
         return false;
    }
};