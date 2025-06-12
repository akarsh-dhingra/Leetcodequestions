class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq; 
// max heap implemented fir
// First k elements ko process kro 
for(int i=0;i<k;i++){
    int element=nums[i];
    pq.push(element);
}
// remaining element ko tabhi insert krenge jab voh root sa chote honge
for(int i=k;i<nums.size();i++){
if(nums[i]>pq.top()){
    pq.pop();
    pq.push(nums[i]);
}
}
int ans=pq.top();
return ans;
    }
};