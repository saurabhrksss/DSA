class Solution {
public:
    vector<vector<int>>dp;
    int starti=0;
    int startj=0;
    int rec(const string &s1,const string &s2)
    {
        int n=s1.size();
        int m=s2.size();
        int lcs=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                if(s1[i]==s2[j]) 
                dp[i][j]=1+dp[i+1][j+1];
                else
                dp[i][j]=0;

                if(dp[i][j]>lcs)
                {
                    if(i==n-(j+dp[i][j]-1)-1)
                    {
                    lcs=dp[i][j];
                    starti=i;
                    startj=j;
                    }
                }
            }
        }
        return lcs;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        int m=rev.size();
        dp.assign(n+1,vector<int>(m+1,0));
        int lcs=rec(s,rev);
        
        return s.substr(starti, lcs);
    }
};