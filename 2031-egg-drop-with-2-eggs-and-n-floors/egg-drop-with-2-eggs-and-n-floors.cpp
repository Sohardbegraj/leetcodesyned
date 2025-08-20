class Solution {
public:
    
    int static t[3][1001];
    int solve(int e,int n){
        if(n==0 || n==1)return n;
        if(e==1)return n;
        if(t[e][n]!=-1){
            return t[e][n];
        }
        int mn=INT_MAX;
        for(int k=1;k<=n;k++){
            int temp=1+max(solve(e-1,k-1),solve(e,n-k));
            mn=min(mn,temp);
        }
        return t[e][n]=mn;
    }
    int twoEggDrop(int n) {
        int e=2;
        memset(t,-1,sizeof(t));
        return solve(e,n);

    }
};
int Solution::t[3][1001];