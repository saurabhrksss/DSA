class Solution {
public:
    vector<vector<int>>dp;
    void checkpalindrome(const string &s)
    {
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(i==j||i+1==j) 
                    dp[i][j]=1;
                    else
                    dp[i][j]=dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
    }
    vector<int>minimum;
    int minimumpartition(int curr,const string &s)
    {
        int n=s.size();
        if(curr==n) return minimum[curr]=0;
        if(minimum[curr]!=-1) return minimum[curr];
        int min=INT_MAX;
        for(int i=curr;i<n;i++)
        {
            if(dp[curr][i])
            {
                int totalcuts=1+minimumpartition(i+1,s);
                min=std::min(totalcuts,min);
            }
        }
        return minimum[curr]=min;
    }
    int minCut(string s) 
    {
        int n=s.size();
        dp.assign(n,vector<int>(n));
        checkpalindrome(s);
        minimum.assign(n+1,-1);
        return minimumpartition(0,s)-1;
    }
};