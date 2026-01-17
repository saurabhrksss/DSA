class Solution {
public:
    const int INF=1e9+7;
    vector<vector<int>>dp;
    int dfs(int curr,int stop,int dst,vector<vector<pair<int,int>>>&adj)
    {
        if(curr==dst) return 0;
        if(stop<0) return INF;
        if(dp[curr][stop]!=-1) return dp[curr][stop];
        int minpath=INF;
        for(auto it:adj[curr])
        {
            int node=it.first;
            int cost=it.second;
            int node_cost=dfs(node,stop-1,dst,adj);
            if(node_cost!=INF)
            minpath=std::min(cost+node_cost,minpath);
        }
        return dp[curr][stop]=minpath;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        dp.assign(n,vector<int>(k+1,-1));
        int ans=dfs(src,k,dst,adj);
        return ans==INF ? -1 : ans;
    }
};



//class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<vector<pair<int,int>>>adj(n);
//         for(int i=0;i<flights.size();i++)
//         {
//             adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
//         }
//         vector<int>dis(n,INT_MAX);
//         queue<pair<pair<int,int>,int>>q;//node level dis
//         q.push({{src,0},0});
//         dis[src]=0;
//         while(!q.empty())
//         {
//             int curr=q.front().first.first;
//             int level=q.front().first.second;
//             int currwt=q.front().second;
//             q.pop();
//             if(level>k) continue;
//             for(auto it:adj[curr])
//             {
//                 int childnode=it.first;
//                 int cost=it.second;
//                 if(currwt+cost<dis[childnode])
//                 {
//                     dis[childnode]=currwt+cost;
//                     q.push({{childnode,level+1},dis[childnode]});
//                 }
//             }
//         }
//         return dis[dst]==INT_MAX ? -1 :dis[dst];
//     }
// };