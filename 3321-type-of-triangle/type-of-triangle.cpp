class Solution {
public:
    bool valid(vector<int>& nums){
        if(nums[0]+nums[1]>nums[2] && nums[2]+nums[0]>nums[1] && nums[1]+nums[2]>nums[0]){
            return true;
        }
        return false;
    }
    string triangleType(vector<int>& nums) {
        string ans="";
        if(valid(nums)){
            if(nums[0]==nums[1]&& nums[1]==nums[2]){
            ans+="equilateral";
            }
            else if( nums[0]==nums[1] || nums[0]==nums[2] || nums[1]==nums[2]){
            ans+= "isosceles";
            }
            else if(nums[0]!=nums[1]&& nums[1]!=nums[2] && nums[0]!=nums[2]){
            ans+="scalene";
            } 
        }
        else{
            ans+="none";
        }
       return ans;
    }
};