class Solution {
public:
    string reorganizeString(string s) {
        // hashing use krkr-> char count
        int hash[26];
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
        }

        // Let's place most freq char at one go:
        char most_freq;
        int freqMax=INT_MIN;
        for(int i=0;i<26;i++){
            if(hash[i]>freqMax){
                freqMax=hash[i];
                most_freq=i+'a';
            }
        }
            int indx=0;
            while(freqMax>0&&indx<s.size()){
                s[indx]=most_freq;
                freqMax--;
                indx+=2;
            }
            if(freqMax!=0){
                return "";
            }
            // if freqMax==0 badhiya hai put the remaining boys in 
            hash[most_freq-'a']=0;

            for(int i=0;i<26;i++){
                while(hash[i]>0){
                    indx=indx>=s.size()?1:indx;
                    s[indx]=i+'a';
                    hash[i]--;
                    indx+=2;
                }
            }
            return s;
    }
};