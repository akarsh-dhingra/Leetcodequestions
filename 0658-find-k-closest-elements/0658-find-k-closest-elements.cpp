class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Step 1: Create a pq
        priority_queue<pair<int,int>>pq;

        vector<int>ans;
        for(int y:arr){
            pq.push({abs(y-x),y});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};