class Solution {
public:
    vector<int>dp;
    int rec(int amount,vector<int>&coins)
    {
        int n=coins.size();
        if(amount==0) return 0;
        if(amount<0) return 1e9;
        if(dp[amount]!=-1) return dp[amount];
        int min=1e9;
        for(auto &it:coins)
        {
            int coin=1+rec(amount-it,coins);
            min=std::min(min,coin);
        }
        return dp[amount]=min;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.resize(amount+1,-1);
        int ans=rec(amount,coins);
        return ans==1e9 ? -1 : ans;
    }
};