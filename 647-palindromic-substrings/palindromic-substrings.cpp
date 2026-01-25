class Solution {
public:
    vector<vector<int>>dp;
    int count(const string &s)
    {
        int n=s.size();
        dp.assign(n,vector<int>(n));
        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(i==j||i+1==j) dp[i][j]=1;
                    else
                    dp[i][j]=dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
                count+=dp[i][j];
            }
        }
        return count;
    }
    int countSubstrings(string s) {
        return count(s);
    }
};