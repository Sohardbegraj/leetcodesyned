class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        int ans = 0;

        if (nums[0] == 1) {
            dp[0][0] = 1;
            dp[0][1] = 0; // no deletion yet
        } else {
            dp[0][0] = 0;
            dp[0][1] = 0; // delete this 0
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] == 1) {
                dp[i][0] = dp[i-1][0] + 1;
                dp[i][1] = dp[i-1][1] + 1;
            } else {
                dp[i][0] = 0;
                dp[i][1] = dp[i-1][0];
            }
            ans = max(ans, dp[i][1]);
        }

        return ans;
    }
};
