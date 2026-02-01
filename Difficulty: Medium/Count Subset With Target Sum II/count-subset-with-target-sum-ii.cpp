class Solution {
  public:
    vector<int>left;
    vector<int>right;
    unordered_map<int,int>mp;
    int ans=0;
    void recleft(int index,int sum)
    {
        int n=left.size();
        if(index==n)
        {
            mp[sum]++;
            return;
        }
        recleft(index+1,sum);
        recleft(index+1,sum+left[index]);
    }
    void recright(int index,int sum,int k)
    {
        int n=right.size();
        if(index==n)
        {
            ans=ans+mp[k-sum];
            return;
        }
        recright(index+1,sum,k);
        recright(index+1,sum+right[index],k);
    }
    int countSubset(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int mid=n/2;
        left.assign(arr.begin(),arr.begin()+mid);
        right.assign(arr.begin()+mid,arr.end());
        recleft(0,0);
        recright(0,0,k);
        return ans;
    }
};