class Solution {
  public:
    bool match(const string &s,const string &p)
    {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[n][m]=1;
        for(int i=0;i<n;i++) dp[i][m]=0;//pattern exhausted
        for(int j=m-1;j>=0;j--)
        {
            if(p[j]=='*') dp[n][j]=1;
            else
            break;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(s[i]==p[j] || p[j]=='?') dp[i][j]=dp[i+1][j+1];
                if(p[j]=='*') dp[i][j]=dp[i][j+1]|dp[i+1][j];
            }
        }
        return dp[0][0];
    }
    bool wildCard(string &s, string &p) {
        // code here
        return match(s,p);
    }
};