class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<int>>dp;
    void checkpalindrome(const string &s)
    {
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(i==j||i+1==j) 
                    dp[i][j]=1;
                    else
                    dp[i][j]=dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
    }
    void rec(int curr,vector<string>&str,const string &s)
    {
        int n=s.size();
        if(curr==n) ans.push_back(str);
        for(int i=curr;i<n;i++)
        {
            if(dp[curr][i])
            {
                str.push_back(s.substr(curr,i-curr+1));
                rec(i+1,str,s);
                str.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        dp.assign(n,vector<int>(n));
        checkpalindrome(s);
        vector<string> str;
        rec(0,str,s);
        return ans;
    }
};