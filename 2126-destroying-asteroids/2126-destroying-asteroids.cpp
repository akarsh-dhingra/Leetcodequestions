class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // Intution is take those asteroids which are having mass == or
        // very near equal to that given asteroids 

       int n=asteroids.size();
       sort(asteroids.begin(),asteroids.end());
       long long total=mass;
       for(int i=0;i<n;i++){
            if(total<asteroids[i]){
                return false;
            }
            total+=asteroids[i];
       }
        return true;
    }
};