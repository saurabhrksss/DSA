class Solution {
public: 
    vector<vector<int>>dp;
    int rec(int i,int j,const string &s1,const string &s2)
    {
        int n=s1.size();
        int m=s2.size();
        if(j==m) return dp[i][j]=1;
        if(i==n) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
        {
            return dp[i][j]=rec(i+1,j+1,s1,s2)+rec(i+1,j,s1,s2);
        }
        else
        {
            return dp[i][j]=rec(i+1,j,s1,s2);
        }
        
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return rec(0,0,s,t);
    }
};