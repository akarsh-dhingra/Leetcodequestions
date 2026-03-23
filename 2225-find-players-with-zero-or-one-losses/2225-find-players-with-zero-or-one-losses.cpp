class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // Ak winners ka array 
        // ak losers ka set 
        //  push all the elements 
    map<int,int>mpp;
    for(int i=0;i<matches.size();i++){
        mpp[matches[i][1]]+=1;
    }
    vector<vector<int>>ans(2,vector<int>());
    for(auto it=mpp.begin();it!=mpp.end();it++){
        if(it->second==1){
            ans[1].push_back(it->first);
        }
    }
    for(int i=0;i<matches.size();i++){
        if(mpp.find(matches[i][0])==mpp.end()){
            mpp[matches[i][0]]=0;
        }

    }
    for(auto it=mpp.begin();it!=mpp.end();it++){
        if(it->second==0){
            ans[0].push_back(it->first);
        }
    }
    return ans;

    }
};