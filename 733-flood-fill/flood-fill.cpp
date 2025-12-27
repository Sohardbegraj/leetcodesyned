class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>& image,int color,int delRow[],int delCol[],int iniColor){
        int n=image.size();
        int m=image[0].size();
        ans[row][col] = color;
        for(int i=0;i<4;i++){
            int nrow=row + delRow[i];
            int ncol=col+ delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m &&image[nrow][ncol] == iniColor && ans[nrow][ncol] != color){
                dfs(nrow, ncol, ans, image, color, delRow, delCol, iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>>ans=image;
        int iniColor =image[sr][sc];
        int delRow[]={0,0,1,-1};
        int delCol[]={1,-1,0,0};
        dfs(sr, sc, ans, image, color, delRow, delCol, iniColor); 
        return ans; 
    }
};