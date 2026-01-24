class Solution {
  public:
    int rec(int aldreadyopen,int lefttobeopen)
    {
        if(aldreadyopen==0 && lefttobeopen==0) return 1;
        int a=0,b=0;
        if(aldreadyopen!=0)
        a=rec(aldreadyopen-1,lefttobeopen);
        if(lefttobeopen!=0)
        b=rec(aldreadyopen+1,lefttobeopen-1);
        return a+b; 
    }
    int findWays(int n) {
        // code here
        if(n%2==1) return 0;
        return rec(0,n/2);
    }
};