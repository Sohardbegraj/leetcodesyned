class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        int N=n/2;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==N){
                return nums[i];
            }
        }
        return 0;
    }
};