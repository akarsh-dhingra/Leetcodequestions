class Solution {
public:
vector<vector<int>> directions{{-1,0},{1,0},{0,1},{0,-1}};
  typedef pair<int,pair<int,int>>p;

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights[0].size();
        int m=heights.size();


        auto isSafe=[&](int x,int y){
            return x>=0 && x<m && y>=0 && y<n;
        };

        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;

        pq.push({0,{0,0}});
        result[0][0]=0;

        while(!pq.empty()){
            int d=pq.top().first;
            pair<int,int>node=pq.top().second;
            int x=node.first;
            int y=node.second;
            pq.pop();

            if(x == m-1 && y == n-1)
                return d;

            for(auto dir:directions){
                int x_=x+dir[0];
                int y_=y+dir[1];


                if(isSafe(x_,y_)){
                    int absDiff=abs(heights[x][y]-heights[x_][y_]);
                    int maxDiff=max(d,absDiff);

                    if(maxDiff<result[x_][y_]){
                        result[x_][y_]=maxDiff;
                        pq.push({result[x_][y_],{x_,y_}});
                    }
                }
            }
        }
    if(result[m-1][n-1]==INT_MAX) return -1;
    return result[m-1][n-1];
    }
};