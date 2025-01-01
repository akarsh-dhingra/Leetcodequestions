class Solution {
public:
// bool check(string s,int indx,int cnt){
//         int n=s.size();
//             if(indx==n){
//              return cnt==0;
//             }
//             if(cnt<0){
//                 return false;
//             }
//             if(s[indx]=='('){
//                 return check(s,indx+1,cnt+1);
//             }
//             else if(s[indx]==')'){
//             return check(s,indx+1,cnt-1);
//             }
//             else{
//             return check(s,indx+1,cnt+1)||check(s,indx+1,cnt-1)||check(s,indx+1,cnt);
//             }

// }
    bool checkValidString(string s) {
       int min=0;
       int max=0;
       for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            min=min+1;
            max=max+1;
        }
        else if(s[i]==')'){
            min=min-1;
            max=max-1;
            if(min<0){
                min=0;
            }
        }
        else{
            min=min-1;
            max=max+1;
             if(min<0){
                min=0;
            }
        }
        if(min<0) min=0;
        if(max<0) return false;
       }
       return (min==0);
           }
};