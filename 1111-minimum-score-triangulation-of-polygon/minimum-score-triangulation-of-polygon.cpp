class Solution {
public:
    int t[51][51];
    int solve(int i,int j,vector<int>values){
        if(j-i+1<3){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int result=INT_MAX;
        for(int k=i+1;k<j;k++){
            int wt=values[i]*values[j]*values[k] 
                    + solve(i,k,values) 
                    +solve(k,j,values);
            result=min(result,wt);
        }
        return t[i][j]=result;
    }
    int minScoreTriangulation(vector<int>& values) {
       int n=values.size();
       memset(t,-1,sizeof(t));
       return solve(0,n-1,values); 
    }
};