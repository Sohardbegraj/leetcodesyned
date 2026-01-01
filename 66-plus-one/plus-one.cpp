class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        // this will insert carry in front
        // digits = {9, 9, 9}; carry = 1;

        // digits = {1, 9, 9, 9}  →  1999 ✅

        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};