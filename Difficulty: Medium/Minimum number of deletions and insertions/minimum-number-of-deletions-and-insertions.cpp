class Solution {
  public:
    vector<vector<int>>dp;
    int lcs(int i,int j,const string &s1,const string &s2)
    {
        if(i==s1.size()||j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+lcs(i+1,j+1,s1,s2);
        return dp[i][j]=std::max(lcs(i,j+1,s1,s2),lcs(i+1,j,s1,s2));
    }
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        int n=s1.size();
        int m=s2.size();
        dp.assign(n,vector<int>(m,-1));
        int len=lcs(0,0,s1,s2);
        return (n+m-len-len);
    }
};