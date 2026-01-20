class Solution {
  public:
    int len(const string &s)
    {
        int n=s.size();
        vector<vector<int>>dp;
        dp.assign(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<=n-1;j++)
            {
                if(s[i]==s[j])
                {
                    if(i==j) 
                    dp[i][j]=1+dp[i+1][j-1];
                    else
                    dp[i][j]=2+dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=std::max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
    int longestPalinSubseq(string &s) {
        // code here
        return len(s);
    }
};