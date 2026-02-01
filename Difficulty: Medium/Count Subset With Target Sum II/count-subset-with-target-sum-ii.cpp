class Solution {
  public:
    vector<int>left;
    vector<int>right;
    unordered_map<int,int>mp;
    int countSubset(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int mid=n/2;
        left.assign(arr.begin(),arr.begin()+mid);
        right.assign(arr.begin()+mid,arr.end());
        int ans=0;
        int leftsize=left.size();
        int rightsize=right.size();
        
        int totalsubset=1<<leftsize;
        for(int mask=0;mask<totalsubset;mask++)
        {
            int sum=0;
            for(int i=0;i<leftsize;i++)
            {
                if(mask & (1<<i))
                {
                    sum+=left[i];
                }
            }
            mp[sum]++;
        }
        int totalcount=1<<rightsize;
        for(int mask=0;mask<totalcount;mask++)
        {
            int sum=0;
            for(int i=0;i<rightsize;i++)
            {
                if(mask & (1<<i))
                {
                    sum+=right[i];
                }
            }
            ans=ans+mp[k-sum];
        }
        return ans;
    }
};