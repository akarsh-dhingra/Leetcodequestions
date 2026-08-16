/*

 // stones[i] == value of ith stone 
        // on each turn the player may remive 
        // The player who removes a stone loses if the sum of the 
        // values of all removed stones is divisible by 3.

        // n%2==0 -> next chance pakka alice ki aayegi toh is sum of stones divisible by 3 hai that means bob lost and alice won
        // n%2!=0 -> 3

*/
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        vector<int>modulated;
        int c0=0;
        int c1=0;
        int c2=0;

        for(int x:stones){
            if(x%3==0) c0++;
            else if(x%3==1) c1++;
            else c2++;
        }
        if (c0 % 2 == 0)
    return c1 > 0 && c2 > 0;
        else
    return abs(c1 - c2) > 2;
    }
};