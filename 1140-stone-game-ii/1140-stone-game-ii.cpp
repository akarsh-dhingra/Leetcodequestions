class Solution {
public:
    int n;
    int t[2][101][101];
    int solveUsingRecAlice(int person,int indx,int M,vector<int>& piles){
        if(indx>=piles.size()) return 0;
        int result=(person==1)?INT_MIN:INT_MAX;
        if(t[person][indx][M]!=-1) return t[person][indx][M];
        int stones=0;
        for(int x=1;x<=min(2*M,n-indx);x++){
            stones+=piles[indx+x-1];
            if(person==1){
                result=max(result,stones+solveUsingRecAlice(0,indx+x,max(M,x),piles));
            }
            else{
                result=min(result,solveUsingRecAlice(1,indx+x,max(M,x),piles));
            }
        }
        return t[person][indx][M]=result;
    }
    int stoneGameII(vector<int>& piles) {
         n=piles.size();
        int M=1;
        memset(t,-1,sizeof(t));
        // 1-> Alice 0 -> Bob
        return solveUsingRecAlice(1,0,M,piles);
    }
};