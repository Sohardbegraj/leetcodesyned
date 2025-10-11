class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());

        // Step 1: compress values (sum duplicates)
        vector<pair<int, long long>> spells; // (damage, totalDamage)
        for (int x : power) {
            if (!spells.empty() && spells.back().first == x) {
                spells.back().second += x;
            } else {
                spells.push_back({x, (long long)x});
            }
        }

        int n = spells.size();
        vector<long long> dp(n, 0);

        dp[0] = spells[0].second;

        for (int i = 1; i < n; i++) {
            // Option 1: don't take current spell
            long long not_take = dp[i - 1];

            // Option 2: take current spell → skip all within (x - 2, x + 2)
            long long take = spells[i].second;
            int j = i - 1;
            while (j >= 0 && spells[i].first - spells[j].first <= 2) {
                j--;
            }
            if (j >= 0) take += dp[j];

            dp[i] = max(take, not_take);
        }

        return dp[n - 1];
    }
};
