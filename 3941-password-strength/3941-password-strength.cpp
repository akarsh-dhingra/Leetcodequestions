class Solution {
public:

    int passwordStrength(string password) {
        int score=0;
        // at most once 
        // set 
        set<char>st;
        for(int i=0;i<password.size();i++){
            if(islower(password[i])&& st.find(password[i])==st.end()){
                score+=1;
                }
            else if(isupper(password[i]) && st.find(password[i])==st.end() )score+=2;
            else if(isalnum(password[i]) && st.find(password[i])==st.end()) score+=3;
            else if(st.find(password[i])==st.end()) score+=5;
            st.insert(password[i]);
        }
    return score;
    }
};