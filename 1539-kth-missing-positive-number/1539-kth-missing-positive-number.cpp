class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int maxi=*max_element(arr.begin(),arr.end());
        int j=0;
        int cnt=0;
        int n=arr.size();
        for(int i=1;i<=maxi;i++){
            if(j<n && arr[j]!=i){
                cnt++;
                if(cnt==k){
                    return i;
                }
            }
            else{ 
            j++;
            }

        }
        int temp=arr[n-1];
        for(int i=cnt;i<k;i++){
            temp++;
        }
        return temp;
    }
};