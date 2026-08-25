class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        // 8,2,3,4,6
        set<int> s;
        for(int x:nums){
            if(x%k==0) s.insert(x);
        }
        int val=k;
        int i=0;
        for(int x:s){
           if(x==val){
            val=k*(i+2);
            i++;
           }
           else{
            return val;
           }
        }
        return k*(s.size()+1);
    }
};