class Solution {
public:
    vector<vector<int>>dp;
    int rec(int i,int j,const string &s1,const string &s2)
    {
        int n=s1.size();
        int m=s2.size();
        if(i==n || j==m)
        {
            if(i==n && j==m) return dp[i][j]=0;
            if(i==n) return dp[i][j]=m-1-j+1;
            if(j==m) return dp[i][j]=n-1-i+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+rec(i+1,j+1,s1,s2);
        return dp[i][j]=std::min(1+rec(i,j+1,s1,s2),1+rec(i+1,j,s1,s2));
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        int length=rec(0,0,str1,str2);
        string str="";
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(str1[i]==str2[j])
            {
                str=str+str1[i];
                i++,j++;
                continue;
            }
            int a=dp[i][j+1];
            int b=dp[i+1][j];
            if(a<b)
            {
                str=str+str2[j];
                j++;
            }
            else
            {
                str=str+str1[i];
                i++;
            }
        }
        while(i<n)
        {
            str+=str1[i];
            i++;
        }
        while(j<m)
        {
            str+=str2[j];
            j++;
        }
        return str;
    }
};