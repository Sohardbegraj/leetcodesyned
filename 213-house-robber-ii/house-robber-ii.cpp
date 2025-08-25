class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 1) return nums[start];

        vector<int> dp(n, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < n; i++) {
            int in = nums[start + i] + dp[i - 2];
            int ex = dp[i - 1];
            dp[i] = max(in, ex);
        }
        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: rob houses [0 … n-2] (exclude last)
        int excludeLast = solve(nums, 0, n - 2);

        // Case 2: rob houses [1 … n-1] (exclude first)
        int excludeFirst = solve(nums, 1, n - 1);

        return max(excludeLast, excludeFirst);
    }
};
