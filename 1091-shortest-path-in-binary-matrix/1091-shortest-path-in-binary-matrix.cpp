class Solution {
public:
vector<vector<int>>directions{{1,1},{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        if(m==0||n==0||grid[0][0]!=0) return -1;

        queue<pair<int,int>>que;
        que.push({0,0});
        grid[0][0]=1;

        auto isSafe=[&](int x,int y){
            return x>=0 && x<m && y>=0 && y<n;
        };
        int levels=1;
        while(!que.empty()){
                int N=que.size();
                while(N--){
                    auto curr=que.front();
                    que.pop();
                    int x=curr.first;
                    int y=curr.second;

                    if(x==m-1 && y==n-1) return levels;

                    for(auto dir:directions){
                        int x_=dir[0]+x;
                        int y_=dir[1]+y;

                        if(isSafe(x_,y_) && grid[x_][y_]==0){
                                que.push({x_,y_});
                                grid[x_][y_]=1;
                        }
                    }
                }
                levels++;
        }
        return -1;
    }
};