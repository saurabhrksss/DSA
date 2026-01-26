class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int min=INT_MAX;
        int n=arr.size();
        for(int i=0;i<=n-2;i++)
        {
            int diff=arr[i+1]-arr[i];
            if(diff<min) min=diff;
        }
        for(int i=0;i<=n-2;i++)
        {
            int diff=arr[i+1]-arr[i];
            if(diff==min)
            {
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};