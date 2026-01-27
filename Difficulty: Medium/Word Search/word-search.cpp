class Solution {
  public:
    vector<pair<int,int>>dimensions={{-1,0},{1,0},{0,-1},{0,1}};
    bool check(int i,int j,int n,int m)
    {
        return i>=0 && j>=0 && i<n && j<m;
    }
    bool dfs(int i, int j, int ptr,vector<vector<char>> &mat,string &word,vector<vector<int>> &visited)
    {
        if(word.size()==ptr) return 1;
        int n=mat.size();
        int m=mat[0].size();
        visited[i][j]=1;
        for(auto it:dimensions)
        {
            int child_i=i+it.first;
            int child_j=j+it.second;
            if(!check(child_i,child_j,n,m)) continue;
            if(!visited[child_i][child_j] && mat[child_i][child_j]==word[ptr])
            {
                if(dfs(child_i,child_j,ptr+1,mat,word,visited)) return 1;
            }
        }
        visited[i][j]=0;
        return 0;
    }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==word[0])
                {
                    if (dfs(i, j, 1, mat, word, visited))
                    return 1;
                }
                
            }
        }
        return 0;
    }
};