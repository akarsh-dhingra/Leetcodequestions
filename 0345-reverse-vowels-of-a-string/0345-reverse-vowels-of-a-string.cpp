class Solution {
public:
bool checkvowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
        return true;
    }
    else return false;
}
    string reverseVowels(string s) {
        // a,e,i,o,u,A,E,I,O,U 
        // vowels ko ak string mai daalkr reverse kre
        // now use this reversed string to be present at the locations.
        int low=0;
        int high=s.size()-1;
        while(low<high){
            if(checkvowel(s[low])&&checkvowel(s[high])){
                swap(s[low],s[high]);
                low++;
                high--;
            }
            else if(!checkvowel(s[low])){
                low++;
            }
            else high--;
        }
        return s;
    }
};