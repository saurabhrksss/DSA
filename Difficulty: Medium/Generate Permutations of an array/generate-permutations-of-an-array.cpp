class Solution {
  public:
    vector<vector<int>>ans;
    vector<int>visited;
    void rec(vector<int>&curr,const vector<int>& arr)
    {
        int n=arr.size();
        if(curr.size()==n) ans.push_back(curr);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                visited[i]=1;
                curr.push_back(arr[i]);
                rec(curr,arr);
                visited[i]=0;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        int n=arr.size();
        visited.assign(n,0);
        vector<int>curr;
        rec(curr,arr);
        return ans;
    }
};