class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int repeating=-1;
        int missing=-1;
        int val=n*n;
        vector<bool>temp(val+1,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val=grid[i][j];
                if(temp[val]){
                    repeating=val;
                }
                else temp[val]=true;
            }
        }
        for(int i=1;i<temp.size();i++){
            if(temp[i]==false) missing=i;
        }

        return {repeating,missing};
    }
};