class Solution {
public:
    // int checkAllOddOrEven(vector<int>& nums1){
    //     int n=nums1.size();
    //     int cnt1=0;
    //     int cnt2=0;
    //     for(int x:nums1){
    //         if(x%2==0) cnt1++;
    //         else cnt2++;
    //     }
    //     if(cnt1==n || cnt2==n) return true;
    //     else return false;
    // }
    bool uniformArray(vector<int>& nums1) {
    //    All even bnana kabhi possible nahi hai
    // Tabhi bna skte ho agr aapke paas all even and no odd ho toh uss case
    //  mai only possible hai varna nahi hai it's not at all possible otherwise.
    int mini=*min_element(nums1.begin(),nums1.end());
    if(mini%2!=0) return true;
    for(int x:nums1){
        if(x%2==1) return false;
    }
    return true;
    }
};