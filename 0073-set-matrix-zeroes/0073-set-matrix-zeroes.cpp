class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>rows(m,0);  /// matrix[...][0]
        vector<int>cols(n,0);  // matrix[0][...]
        int col0=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    // mark the ith row.
                    matrix[i][0]=0;
                    // mark the jth col.
                    if(j!=0){
                        matrix[0][j]=0;
                    } 
                    else{
                        col0=0;
                    }
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]!=0){
                    if(matrix[i][0]==0||matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }

        // When will these three elements be zero??

        if(matrix[0][0]==0){
            for(int j=0;j<n;j++) matrix[0][j]=0;
        }
        if(col0==0){
            for(int i=0;i<m;i++) matrix[i][0]=0;
        }
// Here in this Approach we are using an extra space of O(n) and O(m) 
// Hence in this case we can 
    }
};