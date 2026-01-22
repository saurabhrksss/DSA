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
    int minInsertions(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        int n=s.size();
        dp.assign(n,vector<int>(n,-1));
        return s.size()-lcs(0,0,s,rev);
    }
};