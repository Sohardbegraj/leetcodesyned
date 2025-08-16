class Solution {
public:
    static int t[1001][1001];
    int LCS(string &text1, string &text2,int n,int m){
                if(n==0 || m==0){
                    return 0;
                }
                if(t[n][m]!=-1){
                    return t[n][m];
                }
                if(text1[n-1]==text2[m-1]){
                    return t[n][m]=1+LCS(text1,text2,n-1,m-1);
                }
                else{
                    return t[n][m]=max(LCS(text1,text2,n,m-1),LCS(text1,text2,n-1,m));
                }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= m; j++) {
                    t[i][j] = -1;
                }
            }
        int ans=LCS(text1,text2,n,m);

        return ans;
    }
};
int Solution::t[1001][1001];