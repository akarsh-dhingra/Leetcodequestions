class Solution {
public:
bool checkchar(char c){
    int x=(char)c;
    if(x>=65&&x<=90||x>=97&&x<=122){
        return true;
    }
    else return false;
}
    string reverseOnlyLetters(string s) {
       int low=0;
       int high=s.size()-1;
       while(low<=high){
        if(checkchar(s[low])&&checkchar(s[high])){
            swap(s[low],s[high]);
            low++;
            high--;
        }
        else if(!checkchar(s[low])){
            low++;
        }
        else {
            high--;
        }
       }

    return s;
    }
};