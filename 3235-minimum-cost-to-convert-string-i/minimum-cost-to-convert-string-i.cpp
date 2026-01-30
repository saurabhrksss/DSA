class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,long long>>>adj(26);
        vector<vector<long long>>dis(26,vector<long long>(26,1e18));
        for(int i=0;i<original.size();i++)
        {
            int u=original[i]-'a';
            int v=changed[i]-'a';
            long long wt=cost[i];
            adj[u].push_back({v,wt});
            dis[u][v]=std::min(dis[u][v],wt);
        } 
        for(int i=0;i<26;i++) dis[i][i]=0;
        
        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(dis[i][k]!=1e18 && dis[k][j]!=1e18)
                    {
                        if(dis[i][k]+dis[k][j]<dis[i][j])
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.size();i++)
        {
            int u=source[i]-'a';
            int v=target[i]-'a';
            if(dis[u][v]==1e18) return -1;
            if(u!=v)
            ans=ans+dis[u][v];
        }
        return ans;
    }
};