class Solution {
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    const int INF=1e9+7;
    vector<vector<int>>dis;
    vector<pair<int,int>>dimensions={{-1,0},{1,0},{0,1},{0,-1}};
    bool check(int i,int j,int n)
    {
        return i>=0 && j>=0 && i<n && j<n;
    }
    int minimumCostPath(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        dis.resize(n);
        fill(dis.begin(),dis.end(),vector<int>(n,INF));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({grid[0][0],0,0});
        dis[0][0]=grid[0][0];
        while(!pq.empty())
        {
            auto [distance,row,col]=pq.top();
            pq.pop();
            if(distance>dis[row][col]) continue;
            for(int i=0;i<4;i++)
            {
                int nrow=row+dimensions[i].first;
                int ncol=col+dimensions[i].second;
                if(!check(nrow,ncol,n)) continue;
                if(dis[row][col]+grid[nrow][ncol]<dis[nrow][ncol])
                {
                    dis[nrow][ncol]=dis[row][col]+grid[nrow][ncol];
                    pq.push({dis[nrow][ncol],nrow,ncol});
                }
            }
        }
        return dis[n-1][n-1];
    }
};