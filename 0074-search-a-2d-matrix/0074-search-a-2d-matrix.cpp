class Solution {
public:
    bool BS(int low,int high,vector<int>&arr,int target){
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target) return true;
            if(arr[mid]<target){
                low++;
            }
            else{
                high--;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 1st approahc 
     int rows=matrix.size();  // m
     int cols=matrix[0].size(); // n
        for(auto it:matrix[0]){
                cout<<it<<" ";
        }
        for(int i=0;i<rows;i++){
           if(matrix[i][0]<=target && target<=matrix[i][cols-1]){
           return BS(0,cols-1,matrix[i],target);  // will be called once and hence T.c: O(m+logn)
           }
        }
        return false;
    }
};