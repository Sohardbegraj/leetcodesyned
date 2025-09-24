class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string result;
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }
        long long num = llabs((long long)numerator);
        long long dnum = llabs((long long)denominator);
        long long ans=num/dnum;
        result+=to_string(ans);

        long long rem = num % dnum;
        if (rem == 0) return result;
        result+='.';
        unordered_map<long long, int> remainderPos;
        while (rem != 0) {
            if (remainderPos.find(rem) != remainderPos.end()) {
                // Found repeating remainder
                result.insert(remainderPos[rem], "(");
                result += ")";
                break;
            }

            remainderPos[rem] = result.size();
            rem *= 10;
            result += to_string(rem / dnum);
            rem %= dnum;
        }

        return result;
    }
};