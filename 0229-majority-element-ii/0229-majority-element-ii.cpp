class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        int cnt2=0;
        int el1=INT_MIN;
        int el2=INT_MIN; 
        // 0 0 0 0 0 0 0
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=el2){
                el1=nums[i];
                cnt1+=1;
            }
            else if(cnt2==0 && nums[i] !=el1){
                el2=nums[i];
                cnt2+=1;
            }
            else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int>ans;
        int fre1=0;
        int fre2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1) fre1++;
            if(nums[i]==el2) fre2++;
        }

        int mini=(int)n/3+1; 
        if(fre1>=mini) ans.push_back(el1); 
        if(fre2>=mini) ans.push_back(el2); 
        return ans;
    }
};