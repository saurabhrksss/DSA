class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size();
        vector<int>temp;
        while(!q.empty()){
            int curr=q.front();
            temp.push_back(curr);
            q.pop();
        }
        int i=0;
        int j=n/2;
        for(int k=1;k<=(n/2);k++)
        {
            q.push(temp[i]);
            q.push(temp[j]);
            i++;
            j++;
        }
    }
};