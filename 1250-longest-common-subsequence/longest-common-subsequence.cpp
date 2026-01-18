class Solution {
public:
    vector<vector<int>>dp;
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        dp.assign(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++) dp[n][i]=0;
        for(int i=0;i<=n;i++) dp[i][m]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(text1[i]==text2[j]) dp[i][j]=1+dp[i+1][j+1];
                else
                {
                    dp[i][j]=std::max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};