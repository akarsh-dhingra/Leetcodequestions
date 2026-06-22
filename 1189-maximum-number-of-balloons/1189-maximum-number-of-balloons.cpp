class Solution {
public:
    int maxNumberOfBalloons(string text) {


        unordered_map<char,int>mpp;
        for(auto it:text){
            mpp[it]++;
        }
        
return min({
    mpp['b'],
    mpp['a'],
    mpp['l']/2,
    mpp['o']/2,
    mpp['n']
});
    }
};