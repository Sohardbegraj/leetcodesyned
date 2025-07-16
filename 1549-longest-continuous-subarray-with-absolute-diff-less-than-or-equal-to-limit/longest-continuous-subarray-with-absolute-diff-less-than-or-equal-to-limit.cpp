class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> maxDeque, minDeque;
        int i = 0, res = 0;

        for (int j = 0; j < n; ++j) {
            // Maintain decreasing maxDeque
            while (!maxDeque.empty() && nums[j] > maxDeque.back()) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[j]);

            // Maintain increasing minDeque
            while (!minDeque.empty() && nums[j] < minDeque.back()) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[j]);

            // Shrink window if difference exceeds limit
            while (maxDeque.front() - minDeque.front() > limit) {
                if (nums[i] == maxDeque.front()) maxDeque.pop_front();
                if (nums[i] == minDeque.front()) minDeque.pop_front();
                i++;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};
