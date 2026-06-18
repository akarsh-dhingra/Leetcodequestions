class Solution {
public:
    bool isDigit(char c){
        if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'
        ||c=='9'||c=='0' ){
            return true;
        }
        return false;
    }
    bool isSpecial(char ch){
        string specialChars = "!@#$%^&*()_+-=[]{}|;':\",./<>?";
        for(auto c:specialChars){
            if(c==ch) return true;
        }
        return false;
    }
    int passwordStrength(string password) {
        int ans=0;
        unordered_map<char,int>mpp;
        for(char ch:password){
            
            if(islower(ch)){
                if(mpp.find(ch)==mpp.end()){
                    ans+=1;
                }
            }
            if(isupper(ch)){
                if(mpp.find(ch)==mpp.end()){
                    ans+=2;
                }
            }
            if(isDigit(ch)){
                 if(mpp.find(ch)==mpp.end()){
                    ans+=3;
                }
            }
            if(isSpecial(ch)){
                if(mpp.find(ch)==mpp.end()){
                    ans+=5;
                }
            }
            mpp[ch]++;
        }
        return ans;
    }
};