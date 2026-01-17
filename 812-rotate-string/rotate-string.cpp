class Solution {
public:
    bool rotateString(string s, string goal) {
        int len=s.length();
        for(int k=1;k<=len;k++){
            string temp=s;
            reverse(temp.begin(),temp.begin()+k);
            reverse(temp.begin()+k,temp.end());
            reverse(temp.begin(),temp.end());
            if(temp==goal) return 1;
        }
        return 0;
    }
};