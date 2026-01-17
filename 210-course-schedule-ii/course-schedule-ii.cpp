class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];
            adj[u].push_back(v);
            //u->v
            indegree[v]++;
        }
        vector<int>top;
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) s.push(i);
        }
        while(!s.empty())
        {
            int curr=s.top();
            s.pop();
            top.push_back(curr);
            for(int it:adj[curr])
            {
                indegree[it]--;
                if(indegree[it]==0) s.push({it});
            }
        }
        if(top.size()<n) return {};
        return top;
    }
};