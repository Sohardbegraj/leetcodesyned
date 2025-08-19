class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> merged;
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) merged.push_back(nums1[i++]);
            else merged.push_back(nums2[j++]);
        }
        while (i < m) merged.push_back(nums1[i++]);
        while (j < n) merged.push_back(nums2[j++]);
        int idx=0;
        double median=0;
        if((m+n)%2!=0){
            idx=(m+n-1)/2;
            median=merged[idx];
        }else{
           idx=(m+n)/2; 
            median=(merged[idx]+merged[idx-1])/2.0;
        }
        return median;
    }
};