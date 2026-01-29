class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        string str="";
        unordered_map<char,int>mp;
        queue<char>q;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]==1) q.push(s[i]);
            while(!q.empty())
            {
                char ch=q.front();
                if(mp[ch]==1)
                {
                    str.push_back(ch);
                    break;
                }
                q.pop();
            }
            if(q.empty()) str.push_back('#');
        }
        return str;
    }
};