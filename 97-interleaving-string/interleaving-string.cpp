class Solution {
public:
    vector<vector<int>>dp;
    int rec(int i ,int j,string s1, string s2, string s3)
    {
        int n=s1.size();
        int m=s2.size();
        if(i+j==n+m)
        {
            //both s1 and s2 are exhausted
            int lencovered=n+m;
            if(lencovered==s3.size())
            return 1;
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ptr=i+j;
        int a=0;
        int b=0;
        if(i<n && s1[i]==s3[ptr])
        a=rec(i+1,j,s1,s2,s3);
        if(j<m && s2[j]==s3[ptr])
        b=rec(i,j+1,s1,s2,s3);
        return dp[i][j]=a|b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int len=s3.size();
        // if (s1.size() + s2.size() != s3.size())
        // return false;
        dp.assign(n+1,vector<int>(m+1,-1));
        return rec(0,0,s1,s2,s3);
    }
};