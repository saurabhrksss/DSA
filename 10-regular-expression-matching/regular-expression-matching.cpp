class Solution {
public:
    vector<vector<int>>dp;
    int check(int j,string p)
    {
        int m=p.size();
        while(j<m)
        {
            if(j+1<m&&p[j+1]=='*')
            j=j+2;
            else
            return 0;
        }
        return 1;
    }
    int rec(int i,int j,string s, string p)
    {
        int n=s.size();
        int m=p.size();
        if(i==n && j==m) return dp[i][j]=1;
        if(j==m) return dp[i][j]=0;
        if(i==n) return dp[i][j]=check(j,p);
        if(dp[i][j]!=-1) return dp[i][j];
        if(j+1<m && p[j+1]=='*')
        {
            //equal
            int equal=0;
            if(s[i]==p[j] || p[j]=='.') equal=rec(i+1,j,s,p);
            //not equal
            return dp[i][j]=equal|rec(i,j+2,s,p);
        }
        else
        {
            if(s[i]==p[j] || p[j]=='.') return dp[i][j]=rec(i+1,j+1,s,p);
            return dp[i][j]=0;
        }
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return rec(0,0,s,p);
        return 0;
    }
};