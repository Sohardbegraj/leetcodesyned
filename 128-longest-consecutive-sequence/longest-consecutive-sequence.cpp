class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {
            // start a new sequence if no previous number exists
            if (!s.count(num - 1)) {
                int current = num;
                int length = 1;

                // grow the sequence
                while (s.count(current + 1)) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
