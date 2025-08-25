class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>ans;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        for (int d = 0; d <= n + m - 2; d++) {
            if (d % 2 == 0) {
                reverse(mp[d].begin(), mp[d].end());
            }
            for (int val : mp[d]) {
                ans.push_back(val);
            }
        }

        return ans;
    }
};