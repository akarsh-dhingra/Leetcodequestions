class Solution {
public:
bool checkZeros(vector<int>&hash){
    for(int x:hash){
        if(x!=0) return false;
    }
    return true;
}
   vector<int> findAnagrams(string s, string p) {
     int n=s.size();
     int k=p.size();

    // I know that if two strings are there which are anagrams of each other
    // then obviously their length will be same and their frequency of 
    // occurence will also be the same

    // In order to track frequncy I can use a hasharray
    vector<int>hash(26,0);
    for(int i=0;i<k;i++){
        hash[p[i]-'a']++;
    }
    int i=0;
    int j=0;
    vector<int>result;
    while(j<n){
        hash[s[j]-'a']--;
        
        if(j-i+1==k){
            if(checkZeros(hash)){
                result.push_back(i);
            }
            hash[s[i]-'a']++;
            i++;
        }
        j++;
    }
    return result;
   }
};

