class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
    int n = weight.size();
    vector<int> dp(n, 0);
    vector<int> st;  // decreasing stack of indices

    for (int i = 0; i < n; i++) {
        dp[i] = (i > 0 ? dp[i-1] : 0);

        while (!st.empty() && weight[st.back()] <= weight[i]) {
            st.pop_back();
        }

        if (!st.empty()) {
            int j = st.back();
            dp[i] = max(dp[i], (j > 0 ? dp[j-1] : 0) + 1);
        }

        st.push_back(i);
    }

    return dp[n-1];

    }
};