class Solution {
  public:
    // Function to find the nth catalan number.
    // vector<int>dp;
    // int rec(int n)
    // {
    //     if(n==0 || n==1) return 1;
    //     if(dp[n]!=-1) return dp[n];
    //     int result=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         result+=rec(i)*rec(n-1-i);
    //     }
    //     return dp[n]=result;
    // }
    int findCatalan(int n) {
        // code here
        vector<int>catalan(n+1);
        catalan[0]=1;
        for(int i=1;i<=n;i++)
        {
            catalan[i]=1LL*catalan[i-1]*(4*i-2)/(i+1);
        }
        return catalan[n];
    }
};