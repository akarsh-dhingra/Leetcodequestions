class Solution {
public:
    bool checkVowel(char x){
        if(x=='e'||x=='i'||x=='o'||x=='u'||x=='a'||x=='A'||x=='E'||x=='I'||x=='U'||x=='O'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        // check vowels and reverse them where they 
        // are present
        int l=0;
        int r=s.length()-1;

        while(l<r){
            if(checkVowel(s[l])&&checkVowel(s[r])){
                swap(s[l],s[r]);
                l++;
                r--;
            }
        else if(checkVowel(s[l])==true &&checkVowel(s[r])==false) r--;
        else if(checkVowel(s[r])==true &&checkVowel(s[l])==false) l++;
        else{
            l++;
            r--;
        }
        }
        return s;
    }
};