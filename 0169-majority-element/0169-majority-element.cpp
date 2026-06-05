class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // BOYER MOORE VOTING ALGO:
        // A -> i know it will enoguh no. of times that
        // is greater than n/2 to be a majority 
        // and other candidates wll keep cancelling 
        // and if at any it's cnt value reaches to 0
        // I can surely say that since it was balanced out by 
        // equal no. of elements thus we cannot say that it is.
// Every time a cnt of my elements if it 
// reaches to 0 I"ll change my majority el to a newer value why?? Because uptill this 
// point I am not sure that whether this element is a majority or not since it was cancelled out by equal no. of elements so that is why I am kind of you can say starting a new journey of cnting now here cnt is not denoting the actual cnt value but it is just a simple variable depicting us the no. of votes that are there in majority for a particular el.
// 
       int cnt=0;
       int n=nums.size();
        unordered_map<int,int>mpp;
       for(auto it:nums){
            mpp[it]++;
       }
        int ans=0;
       for(auto it:mpp){
        if(it.second>n/2){
        ans= it.first;
        }
       }
       return ans;
        }
    };