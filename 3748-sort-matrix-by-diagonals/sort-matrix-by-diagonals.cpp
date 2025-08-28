class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int, vector<int>> mp;

        // Step 1: Collect diagonals
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(grid[i][j]);
            }
        }

        // Step 2: Sort according to rules
        for (auto &it : mp) {
            if (it.first >= 0) {
                // bottom-left including main diagonal → descending
                sort(it.second.begin(), it.second.end());
            } else {
                sort(it.second.begin(), it.second.end(), greater<int>());
                // top-right → ascending
            }
        }

        // Step 3: Refill diagonals
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }

        return grid;
    }
};
