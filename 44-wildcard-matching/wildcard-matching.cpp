class Solution {
public:
    vector<vector<int>>dp;
    bool match(int i,int j,const string &s,const string &p)
    {
        int n=s.size();
        int m=p.size();
        if(i==n && j==m ) return dp[i][j]=1;
        if(j==m) return dp[i][j]=0;
        if(i==n)
        {
            if(p[j]=='*')
            {
                if(match(i,j+1,s,p)) return dp[i][j]=1;
            }
            return dp[i][j]=0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] && islower(s[i]) && islower(p[j])) return dp[i][j]=match(i+1,j+1,s,p);
        if(s[i]!=p[j] && islower(s[i]) && islower(p[j])) return dp[i][j]=false;
        if(p[j]=='?') return match(i+1,j+1,s,p);
        if(p[j]=='*')
        {
            return dp[i][j]=match(i,j+1,s,p) | match(i+1,j,s,p);
        }
        return dp[i][j]=false;
    } 
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return match(0,0,s,p);
    }
};