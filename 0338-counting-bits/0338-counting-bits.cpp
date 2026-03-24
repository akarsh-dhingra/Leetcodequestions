class Solution {
public:
    vector<int> countBits(int n) {
        // If I get the no. of set bits for each of the number between 1 to n then 
        // I can evenutally get my answer
    vector<int>ans;

        for(int i=0;i<=n;i++){
            int x=__builtin_popcount(i);
            ans.push_back(x);
        }
        return ans;

    }
};