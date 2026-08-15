class Solution {
public:
    
    int longestSubsequence(vector<int>& nums) {
        // Brute Force sochta hu 
        // Generate all subsequneces or subsets 
        // Doh samee cheezon ka xor krne par always 0 aata hai !! 
        // and then iterate over each of them one by one by one 
        int n=nums.size();
        int xorr=0;
        bool allZero=true;
        for(int x:nums) {
            xorr^=x;
           if(x!=0)allZero=false;
        }
        if(allZero) return 0;
        else return xorr==0?n-1:n;

    }
};