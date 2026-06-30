class Solution {
public:
    int beautySum(string s) {
        // Frequency -> hashmap 
        // Brute fgorce genertate all substrings and then calculate their beauty max_freq-min_freq sum them all and return
        int sum=0;
        int n=s.length();
        
        for(int i=0;i<n;i++){
            
            for(int j=i;j<n;j++){
                vector<int>freq(26,0);    
                string x=s.substr(i,j-i+1);
                for(char ch:x){
                    freq[ch-'a']++;
                }
                int maxi=0;
                int mini=INT_MAX;
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                        maxi=max(maxi,freq[k]);
                        mini=min(mini,freq[k]);
                    }
                }
            sum+=(maxi-mini);
            }
        }
        return sum;
    }
};