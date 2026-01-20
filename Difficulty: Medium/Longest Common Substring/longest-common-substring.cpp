class Solution {
  public:
    vector<vector<int>>count;
    vector<vector<int>>dp;
    int common(int i,int j,const string &s1,const string &s2)
    {
        if(i==s1.size()||j==s2.size()) return 0;
        if(count[i][j]!=-1) return count[i][j];
        if(s1[i]==s2[j]) return count[i][j]=1+common(i+1,j+1,s1,s2);
        return 0;
    }
    int lcs(int i,int j,const string &s1,const string &s2)
    {
        if(i==s1.size()||j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int count=common(i,j,s1,s2);
        int a=lcs(i,j+1,s1,s2);
        int b=lcs(i+1,j,s1,s2);
        return dp[i][j]=std::max({count,a,b});
    }
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.size(),m=s2.size();
        count.assign(n+1,vector<int>(m+1,-1));
        dp.assign(n+1,vector<int>(m+1,-1));
        return lcs(0,0,s1,s2);
    }
};