class Solution {
public:
    string processStr(string s) {
        // lowercase english letters: a,b,c ....z
        // special chars: *, #, and %. 
        string result="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(islower(s[i])){
                result.push_back(s[i]);
            }
            else if(s[i]=='#'){
                result+=result;
            }
            else if(s[i]=='%'){
                reverse(result.begin(),result.end());
            }
            else{
               if(result.size()>0) result.pop_back();
            }
        }
        return result;
    }
};