class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==0){
            return 0;
        }
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1]);
            }
        }
        return triangle[0][0];
    }

};