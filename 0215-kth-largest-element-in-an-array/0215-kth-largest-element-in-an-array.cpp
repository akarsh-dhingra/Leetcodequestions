class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    // priority_queue<int,vector<int>,greater<int>> minHeap;
    priority_queue<int>maxHeap;
    for(int i=0;i<nums.size() - k + 1;i++){
        maxHeap.push(nums[i]);
    }
    for(int i=nums.size() - k + 1;i<nums.size();i++){
        if(nums[i]<maxHeap.top()){
               maxHeap.pop();
               maxHeap.push(nums[i]);
        }
    }
    return maxHeap.top();
    }
};