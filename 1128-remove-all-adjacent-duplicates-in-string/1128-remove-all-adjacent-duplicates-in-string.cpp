class Solution {
public:
int findlength(string s){
   int i=0;
   while(s[i]!='\0'){
    i++;
   }
   return i;
}
    string removeDuplicates(string s) {
        int len= findlength(s);
        int indx=0;
        while(s[indx]!='\0'){
            if(s[indx]==s[indx+1]){
                s.erase(s.begin()+indx,s.begin()+indx+2);
                indx=0;
            }
         else indx++;
        }
        return s;
    }
};