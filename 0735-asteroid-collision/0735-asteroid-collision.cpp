class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
     vector<int>st;

     for(int a:asteroids){
        if(a>0) st.push_back(a);
        else{
            while(!st.empty()&& st.back()>0 &&st.back()<abs(a)){
                // >0 because We know that <0
                st.pop_back();
            }
            if(!st.empty()&&st.back()==abs(a))st.pop_back();
            // [8,-8]
            else if(st.empty()||st.back()<0){
                st.push_back(a);
            }
        }
     }
    return st;

    }
};