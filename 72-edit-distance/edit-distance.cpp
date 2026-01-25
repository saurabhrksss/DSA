class Solution {
public:
    int minimumdistance(const string &s1,const string &s2)
    {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int j=0;j<=m;j++) dp[n][j]=m-j;
        for(int i=0;i<=n;i++) dp[i][m]=n-i;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(s1[i]==s2[j])
                {
                    dp[i][j]=dp[i+1][j+1];
                }
                else
                {
                    int replace=1+dp[i+1][j+1];
                    int del=1+dp[i+1][j];
                    int add=1+dp[i][j+1];
                    dp[i][j]=std::min({replace,del,add});
                }
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        return minimumdistance(word1,word2);
    }
};