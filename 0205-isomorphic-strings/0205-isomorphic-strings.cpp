class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int a=s.size();
        int hashans[256]={0};
        bool istcharmapped[256]={0};
       for(int i=0;i<s.size();i++){
        if(hashans[s[i]]==0 && istcharmapped[t[i]]==0){
            hashans[s[i]]=t[i];
            istcharmapped[t[i]]=1;
        }
       }
       for(int i=0;i<t.size();i++){
             if(char(hashans[s[i]])!=t[i] ){
                return false;
             }
       }
       return true;
    }
};