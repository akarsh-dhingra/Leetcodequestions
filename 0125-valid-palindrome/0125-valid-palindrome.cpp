class Solution {
public:
bool remove(char ch){
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){ // char is alphanumeric
        return false;
    }
    else return true;
}
    bool isPalindrome(string s) {
       // faltu character hatane hai.
        string temp="";
        for(int i=0;i<s.size();i++){
            if(!remove(s[i])){
              temp.push_back(s[i]);
            }
        }
         for(int i=0;i<temp.size();i++){
        if(temp[i]>='A'&&temp[i]<='Z'){
            temp[i]=temp[i]-'A'+'a';
         }
        }
        int low=0;
        int high=temp.size()-1;
        while(low<high){
            if(temp[low]==temp[high]){
                low++;
                high--;
            }
            else return false;
        }
      return true;
    }
};