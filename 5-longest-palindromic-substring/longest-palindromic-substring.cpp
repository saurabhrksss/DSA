class Solution {
public:
    vector<vector<int>>dp;
    int longest=INT_MIN;
    int startindex=0;
    void palindrome(const string &s)
    {
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(i==j || i+1==j)
                    {
                        dp[i][j]=1;
                    }
                    else
                    {
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                else
                {
                    dp[i][j]=0;
                }

                if(dp[i][j]==1)
                {
                    int len=j-i+1;
                    if(len>longest)
                    {
                        longest=len;
                        startindex=i;
                    }
                }
            }
        }
    }
    string longestPalindrome(string s) 
    {
        int n=s.size();
        dp.assign(n,vector<int>(n,-1));
        palindrome(s);
        return s.substr(startindex,longest);
    }
};