class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            // removal of elements outside the curr window.
            if(!dq.empty()&&dq.front()<=i-k){
                dq.pop_front();
            }
            //if added element is greater than the back element disturbin monotonicity
            while(!dq.empty()&&nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i); // insert from the back i.e. right side.
            if(i>=k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};