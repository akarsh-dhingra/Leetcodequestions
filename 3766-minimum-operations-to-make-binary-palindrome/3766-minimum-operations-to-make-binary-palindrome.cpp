class Solution {
public:
    bool checkPalin(int n){
        string temp="";
        while(n>0){
            temp+=char('0' + (n & 1));
            n=n>>1;
        }
        int i=0;
        int j=temp.size()-1;
        while(i<j){
            if(temp[i]==temp[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        // ak string bethao 
        // aur ak palindrome ka function bethao
        // kuch next greater aur next smaller vaala bhi lg rha hai 
        vector<int>ans;
        vector<int>pali;
        for(int i=1;i<=5000;i++){
            if(checkPalin(i)){
                pali.push_back(i);
            }
        }
        for(int x:nums){
            int minDist=INT_MAX;
            for(int i:pali){
                if(abs(x-i)<minDist){
                    minDist=min(minDist,abs(x-i));
                }
            }
            ans.push_back(minDist);
        }
        return ans;
    }
};