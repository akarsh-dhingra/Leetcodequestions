class Solution {
public:
    int beautySum(string s) {
        // Frequency -> hashmap 
        // Brute fgorce genertate all substrings and then calculate their beauty max_freq-min_freq sum them all and return
        int sum=0;
        int n=s.length();
        
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                int maxi=0;
                int mini=INT_MAX;
                freq[s[j]-'a']++;
                for(int i=0;i<26;i++){
                    if(freq[i]>0){
                        maxi=max(maxi,freq[i]);
                        mini=min(mini,freq[i]);
                    }
                }
                sum+=(maxi-mini);
            }
        }
        return sum;
    }
};