class Solution {
public:
    int passwordStrength(string password) {
        int ans=0;
        set<char>st;

        for(char ch:password){
            st.insert(ch);
            
        }
        for(auto it:st){
            if(islower(it)) ans+=1;
           else if(isupper(it)) ans+=2;
           else if(isalnum(it)) ans+=3;
           else ans+=5;
        }
        return ans;
    }
};