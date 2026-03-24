class Solution {
public:
    // int countSetBits(int n){
    //     int count=0;
    //     while(n>0){
    //         if(n&1) count++;
    //         n=n>>1;
    //     }
    //     return count;
    // }
    // int countSetBits2(int x){

    // }
    vector<int> countBits(int n) {
        // If I get the no. of set bits for each of the number between 1 to n then 
        // I can evenutally get my answer
    vector<int>ans(n+1,0);

        for(int i=1;i<=n;i++){
            if(i%2==0){

                ans[i]=ans[i/2];
            }
            else{
                ans[i]=ans[i/2]+1;
            }
        }
        return ans;

    }
};