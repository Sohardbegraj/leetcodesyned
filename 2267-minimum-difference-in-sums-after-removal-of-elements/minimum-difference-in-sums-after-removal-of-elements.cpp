class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int k = n / 3;

        vector<long long> leftSum(n), rightSum(n);

        priority_queue<int> maxHeap; // to track smallest sum from left k*2 elements
        long long left = 0;
        for (int i = 0; i < 2 * k; ++i) {
            maxHeap.push(nums[i]);
            left += nums[i];
            if (maxHeap.size() > k) {
                left -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == k) leftSum[i] = left;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long right = 0;
        for (int i = n - 1; i >= k; --i) {
            minHeap.push(nums[i]);
            right += nums[i];
            if (minHeap.size() > k) {
                right -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == k) rightSum[i] = right;
        }

        long long res = LLONG_MAX;
        for (int i = k - 1; i < 2 * k; ++i) {
            res = min(res, leftSum[i] - rightSum[i + 1]);
        }

        return res;
    }
};
