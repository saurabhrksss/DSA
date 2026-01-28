class Solution {
public:
    const long long INF=1e18;
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        vector<vector<pair<int,int>>>indegree(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            indegree[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dis(n,INF);
        priority_queue< tuple<long long,int> ,vector<tuple<long long,int>>,greater<tuple<long long,int>>>pq;
        pq.push({0,0});
        dis[0]=0;
        while(!pq.empty())
        {
            auto [distance,curr]=pq.top();
            pq.pop();
            if(distance>dis[curr]) continue;
            for(auto [child,wt]:adj[curr])
            {
                if(distance+wt<dis[child])
                {
                    dis[child]=distance+wt;
                    pq.push({dis[child],child});
                }
            }
            for(auto [parent,wt]:indegree[curr])
            {
                if(dis[curr]+2ll*wt<dis[parent])
                {
                    dis[parent]=dis[curr]+2*wt;
                    pq.push({dis[parent],parent});
                }
            }
        }
        return dis[n-1]==INF ? -1 : dis[n-1];
    }
};