class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     // sbse pehle curr_ch i.e joh compare krna hai voh =0 
     string ans="";
     int indx=0; // indx will help in iterating
// jab bhi nah pta ho ki kya kha break kaise ak inf loop
 while(true){
char curr_ch=0;
for(auto str:strs){
    if(indx>=str.length()){
        curr_ch=0;
        break;
    }
    if(curr_ch==0){
        curr_ch=str[indx];
    }
    else if(curr_ch!=str[indx]){
        curr_ch=0; // kyunki unequal aaya hai toh definitely yeh answer ka part nahi hoga
        break;
    }
}
if(curr_ch==0){
    break;
}
    ans.push_back(curr_ch);
    indx++;
     }
return ans;
    }
};