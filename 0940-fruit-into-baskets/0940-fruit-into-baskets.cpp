class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // find the maximum length of subarray containing at 
        // most two fruit types.
        int n=fruits.size();
        int maxlen=0;
        int r=0;
        int l=0;
        map<int,int>mpp;
        while(r<n){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                while(mpp.size()>2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]]==0){
                        mpp.erase(fruits[l]);
                    }
                    l++;
                }
            }
            else{
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};