class Solution {
public:
    bool isDigit(char c){
        if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'
        ||c=='9'||c=='0' ){
            return true;
        }
        return false;
    }
    int passwordStrength(string password) {
        int ans=0;
        set<char>st;

        for(char ch:password){
            st.insert(ch);
            
        }
        for(auto it:st){
            if(islower(it)) ans+=1;
           else if(isupper(it)) ans+=2;
           else if(isDigit(it)) ans+=3;
           else ans+=5;
        }
        return ans;
    }
};