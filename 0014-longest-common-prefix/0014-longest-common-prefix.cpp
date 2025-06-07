class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // if there a n no. of elements given in  a vector
        // how to perform comparison one wth others
        string ans="";
        int i=0; //used for iterating through each string.
        int n=strs.size();
        while(true){
            char curr_ch=0;
            for(auto str:strs){
                // if length exceeded yahi fasenge
                if(i>=str.size()){
                    curr_ch=0; // this lines means aage aur kuch nahi hai 
                    break;
                }
                // if curr_ch==0
                if(curr_ch==0){
                    curr_ch=str[i];
                }
                else if(str[i]!=curr_ch){
                    curr_ch=0;
                    break;
                }
            }
            if(curr_ch==0){
                break;
            }
            ans.push_back(curr_ch);
            i++;
        }
        return ans;
    }
};