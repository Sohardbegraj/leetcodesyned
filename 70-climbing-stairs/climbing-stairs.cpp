class Solution {
public:
    int solve(vector<int>&memo,int n){
        if(n==0)return 1;
        if(n==1)return 1;
        if(memo[n]!=-1){
            return memo[n];
        }
        return memo[n]=solve(memo,n-1)+solve(memo,n-2);
    }
    int climbStairs(int n) {
        if (n <= 3) return n;
        vector<int>memo(n+1,-1);
        return solve(memo,n);
    }
};