class Solution {
public:
    int lcs(const string &s1,const string &s2)
    {
        int n=s1.size();
        int m=s2.size();
        vector<int>prev(m+1,0);
        for(int i=n-1;i>=0;i--)
        {
            vector<int>curr(m+1);
            for(int j=m-1;j>=0;j--)
            {
                if(s1[i]==s2[j]) 
                curr[j]=1+prev[j+1];
                else
                curr[j]=std::max(curr[j+1],prev[j]);
            }
            prev=curr;
        }
        return prev[0];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int lenoflcs=lcs(word1,word2);
        return n+m-2*lenoflcs;
    }
};