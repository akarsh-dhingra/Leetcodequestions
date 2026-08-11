class Solution {
public:
    int n;
    // int diff=INT_MIN;
    vector<int>t;
    int solveUsingRec(int i,vector<int>& stoneValue){
        if(i>=n) return 0;
        
        int diff=stoneValue[i]-solveUsingRec(i+1,stoneValue);
        if(t[i]!=-1) return t[i];
        if(i+1<n){
            diff=max(diff,stoneValue[i]+stoneValue[i+1]-solveUsingRec(i+2,stoneValue));
        }
        if(i+2<n){
            diff=max(diff,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solveUsingRec(i+3,stoneValue));   
        }
        return t[i]=diff;
    }
    int solveUsingTab(vector<int>& stoneValue){
        int n=stoneValue.size();
        vector<int>t(n+1,0);
        for(int i=n-1;i>=0;i--){
            t[i]=stoneValue[i]-t[i+1];
            if(i+1<n && i+2<=n){
                t[i]=max(t[i],stoneValue[i]+stoneValue[i+1]-t[i+2]);
            }
            if(i+1<n && i+2<n && i+3<=n){
                t[i]=max(t[i],stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-t[i+3]);
            }
            
        }
        return t[0];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        t.resize(n+1,-1);
        int diff=solveUsingTab(stoneValue);   
        
        if(diff<0){
            return "Bob";
        }
        if(diff>0){
            return "Alice";
        }
        return "Tie";
    }
};