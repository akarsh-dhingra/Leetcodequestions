class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 1st approahc 
     int rows=matrix.size();  // m
     int cols=matrix[0].size(); // n
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==target) return true;
            }
        }
        return false;
    }
};