class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int maxi = 0, n = s.length();

        while (j < n) {
            mp[s[j]]++;

            while (mp[s[j]] > 1) {
                mp[s[i]]--;
                i++;
            }

            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};
