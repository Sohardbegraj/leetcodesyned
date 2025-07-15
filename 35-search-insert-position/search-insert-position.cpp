class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(target>nums[n-1]){
            return n;
        }
        else if(target<=nums[0]){
            return 0;
        }
        int start=0;
        int end=n-1; 

        while(start<=end){
            int med = start + (end - start) / 2;
            if(nums[med]==target){
                return med;
            }else if(nums[med]>target){
                end=med-1;
            }
            else{
                start=med+1;
            }
        
        }
        return start;
    }
};