class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
    int n = temp.size();
    vector<int> answer(n, 0);
    stack<pair<int, int>> st; // pair: {temperature, index}

    for (int i = n - 1; i >= 0; --i) {
        // Pop all elements that are less than or equal to current temperature
        while (!st.empty() && st.top().first <= temp[i]) {
            st.pop();
        }

        if (!st.empty()) {
            answer[i] = st.top().second - i;
        }

        st.push({temp[i], i});
    }

    return answer;
}

};
