class Solution {
public:

    int passwordStrength(string password) {
        int score=0;
        // at most once 
        // set 
        set<char>st;
        for(int i=0;i<password.size();i++){
            if(st.find(password[i])!=st.end()){
                continue;
            }
            else{
            if(islower(password[i]))score+=1;
            else if(isupper(password[i]))score+=2;
            else if(isalnum(password[i])) score+=3;
            else score+=5;
            }
            st.insert(password[i]);
        }
    return score;
    }
};