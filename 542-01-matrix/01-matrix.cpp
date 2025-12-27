class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>ans=mat;
        int delrow[]={0,0,1,-1};
        int delcol[]={1,-1,0,0};
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;

            ans[row][col]=steps;

            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && visited[nrow][ncol]==false){
                    visited[nrow][ncol]=true;
                    q.push({{nrow,ncol},steps+1});
                }

            }
        }

        return ans;
    }
};