class Solution {
public:
    vector<vector<int>>dp;
    int rec(int i,int j,const string &s)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j])
        {
            if(i==j) 
            return dp[i][j]=1+rec(i+1,j-1,s);
            else
            return dp[i][j]=2+rec(i+1,j-1,s);
        }
        return dp[i][j]=std::max(rec(i,j-1,s),rec(i+1,j,s));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        dp.assign(n,vector<int>(n,-1));
        return rec(0,n-1,s);
    }
};