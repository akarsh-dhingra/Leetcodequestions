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
            bool left =checkVowel(s[l]);
            bool right=checkVowel(s[r]);
            if(left&&right){
                swap(s[l],s[r]);
                l++;
                r--;
            }
            else if (!right){
                r--;
            }      
            else l++;
        }
        return s;
    }
};