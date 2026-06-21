class Solution {
public:
vector<int> extractDigit(long long num ){
    string s = to_string(num);
    return {s.front()-'0', s.back()-'0'};

    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();
        int cnt=0;
    for(int i=0;i<n;i++){
        long long sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(sum%10==x){
                vector<int>curr=extractDigit(sum);
                if(curr[0]==x && curr[1]==x){
                cnt++;
                 }
            }
        }
    }
    return cnt;
    }
};