class Solution {
public:
    bool rotateString(string s, string goal) {
        int len=s.length();
        for(int k=0;k<=len-1;k++){
            string temp=s;
            reverse(temp.begin(),temp.begin()+k+1);
            reverse(temp.begin()+k+1,temp.end());
            reverse(temp.begin(),temp.end());
            if(temp==goal) return 1;
        }
        return 0;
    }
};