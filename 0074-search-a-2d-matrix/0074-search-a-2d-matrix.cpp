class Solution {
public:
   
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 1st approahc 
    int rows=matrix.size();  // m
    int cols=matrix[0].size(); // n
    int low=0;
    int high=(rows*cols)-1;
    
    while(low<=high){
        int mid=(low+high)/2;
        int row=mid/cols;
        int col=mid%cols;

        if(matrix[row][col]==target){
            return true;
        }
        else if(matrix[row][col]<target){
            low++;
        }
        else{high--;}
    }
        return false;
    }
};