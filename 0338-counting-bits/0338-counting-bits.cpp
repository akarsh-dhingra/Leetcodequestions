class Solution {
public:
    int countSetBits(int n){
        int count=0;
        while(n>0){
            if(n&1) count++;
            n=n>>1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        // If I get the no. of set bits for each of the number between 1 to n then 
        // I can evenutally get my answer
    vector<int>ans;

        for(int i=0;i<=n;i++){
            int x=countSetBits(i);
            ans.push_back(x);
        }
        return ans;

    }
};