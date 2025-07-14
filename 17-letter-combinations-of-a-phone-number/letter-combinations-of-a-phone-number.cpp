class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        unordered_map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        string current;
        backtrack(0, digits, phoneMap, current, ans);
        return ans;
    }

private:
    void backtrack(int index, const string& digits, const unordered_map<char, string>& phoneMap,
                   string& current, vector<string>& ans) {
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        const string& letters = phoneMap.at(digits[index]);
        for (char ch : letters) {
            current.push_back(ch);
            backtrack(index + 1, digits, phoneMap, current, ans);
            current.pop_back();  // backtrack
        }
    }
};
