class Solution {
public:
    const long long INF=1e18;
    vector<vector<pair<int,long long>>>adj;
    vector<vector<long long>>dis;
    set<int>len;
    unordered_map<string,int>id;
    vector<long long>dp;
    long long rec(int index,string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost)
    {
        int mark=adj.size();
        int n=source.size();
        int m=changed.size();
        if(index==n) return 0;
        if(dp[index]!=-1) return dp[index];
        long long ans=INF;
        if(source[index]==target[index])
        ans=rec(index+1,source,target,original,changed,cost);
        for(auto &it:len)
        {
            if(index+it>n) continue;
            string s1=source.substr(index,it);
            string s2=target.substr(index,it);
            if(!id.count(s1) || !id.count(s2)) continue;
            long long price=dis[id[s1]][id[s2]];
            if(price==INF) continue;
            long long next=rec(index+it,source,target,original,changed,cost);
            if(next!=INF)
            ans=std::min(ans,price+next);
        }
        return dp[index]=ans;
    }
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n=source.size();
        int m=original.size();
        int mark=0;
        
        for(int i=0;i<m;i++)
        {
            string s1=original[i];
            len.insert(s1.size());
            if(id.find(s1)==id.end())
            {
                id[s1]=mark++;
            }
            string s2=changed[i];
            len.insert(s2.size());
            if(id.find(s2)==id.end())
            {
                id[s2]=mark++;
            }
        }
        adj.resize(mark);
        dis.assign(mark,vector<long long>(mark,INF));
        for(int i=0;i<m;i++)
        {
            int u=id[original[i]];
            int v=id[changed[i]];
            long long wt=cost[i];
            adj[u].push_back({v,wt});
            dis[u][v]=std::min({dis[u][v],wt});
        }
        for(int i=0;i<mark;i++) dis[i][i]=0;
        
        for(int k=0;k<mark;k++)
        {
            for(int i=0;i<mark;i++)
            {
                for(int j=0;j<mark;j++)
                {
                    if(dis[i][k]!=1e18&&dis[k][j]!=1e18)
                    {
                        if(dis[i][k]+dis[k][j]<dis[i][j])
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
        dp.assign(n+1,-1);
        long long ans=rec(0,source,target,original,changed,cost);
        return ans==INF ? -1 : ans;
    }
};