class Solution {
public:
// int findlength(string s){
//    int i=0;
//    while(s[i]!='\0'){
//     i++;
//    }
//    return i;
// }
    string removeDuplicates(string s) {
        string ans={};
        int indx=0;
        while(indx<s.length()){
            // same
            // ans ka rightmost character and joh apna string ka currect character are same 
          if(ans.length()>0&&ans[ans.length()-1]==s[indx]){
            ans.pop_back();
          }
          else{
            ans.push_back(s[indx]);
          }
          indx++;
        }
        return ans;














        // int len= findlength(s);
        // int indx=0;
        // while(s[indx]!='\0'){
        //     if(s[indx]==s[indx+1]){
        //         s.erase(s.begin()+indx,s.begin()+indx+2);
        //         indx=0;
        //     }
        //  else indx++;
        // }
        // return s;
    }
};