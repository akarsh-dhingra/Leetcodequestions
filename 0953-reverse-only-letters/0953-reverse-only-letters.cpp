class Solution {
public:
void reversedd(string s){
    int low=0;
    int high=s.size()-1;
    while(low<high){
       if(isalpha(s[low])==true && isalpha(s[high])==true) {
        swap(s[low],s[high]);
        low++;
        high--;
    }
    else if(isalpha(s[low])==false){
        low++;
    }
    else high--;
    }
}
    string reverseOnlyLetters(string s) {
    int low=0;
    int high=s.size()-1;
    while(low<high){
       if(isalpha(s[low]) && isalpha(s[high])) {
        swap(s[low],s[high]);
        low++;
        high--;
    }
    else if(!isalpha(s[low])){
        low++;
    }
    else high--;
    }
        return s;
    }
};