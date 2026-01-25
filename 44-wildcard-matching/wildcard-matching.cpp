class Solution {
public:
    vector<vector<int>>dp;
    bool isallstar(int j,const string &p)
    {
        int m=p.size();
        for(int i=j;i<m;i++)
        if(p[i]!='*') return false;
        return true;
    }
    bool match(int i,int j,const string &s,const string &p)
    {
        int n=s.size();
        int m=p.size();
        if(i==n && j==m) return dp[i][j]=1;
        if(j==m) return dp[i][j]=0;
        if(i==n)
        {
            return isallstar(j,p);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        //match
        if(s[i]==p[j] || p[j]=='?')
        return dp[i][j]=match(i+1,j+1,s,p);
        //*
        if(p[j]=='*')
        return dp[i][j]=match(i,j+1,s,p)|match(i+1,j,s,p);
        //not equal
        return dp[i][j]=0;
    } 
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return match(0,0,s,p);
    }
};