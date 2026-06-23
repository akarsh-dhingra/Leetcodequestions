class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    // Create an unordered map for freq
    unordered_map<int,int>mpp;  

    for(auto it:nums){
        mpp[it]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
    for(auto it:mpp){
        minheap.push({it.second,it.first});
        if(minheap.size()>k){
            minheap.pop();
        }
    }
    vector<int>ans;
    while(!minheap.empty()){
        auto curr=minheap.top();
        ans.push_back(curr.second);
        minheap.pop();
    }
    return ans;

    }
};