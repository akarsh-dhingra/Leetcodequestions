class Solution {
public:
    bool allZeros(vector<int>&counter){
        for(int i:counter){
            if(i!=0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        // Naive approach create all anagrams of p 
        // find s.substr(p) in s you will get initial indexes if they exist else -1 put it in the arr.
        vector<int>result;
        int n=s.size();
        vector<int>counter(26,0);

        for(int i=0;i<p.length();i++){
            char ch=p[i];
            counter[ch-'a']++;
        }

        int k=p.length();

        int ans=0;
        int i=0;
        int j=0;
        while(j<n){
            counter[s[j]-'a']--;
            
            if(j-i+1==k){
                if(allZeros(counter)){
                    ans++;
                    result.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};