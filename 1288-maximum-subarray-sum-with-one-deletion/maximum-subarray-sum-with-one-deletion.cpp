class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int maxSum = arr[0];
        int noDelete = arr[0];
        int oneDelete =0;

        for (int i = 1; i < n; ++i) {
            oneDelete = max(oneDelete + arr[i], noDelete); 
            noDelete = max(arr[i], noDelete + arr[i]); 
            maxSum = max({maxSum, noDelete, oneDelete});
        }

        return maxSum;
    }
};
