class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int even=0;
        int odd=0;

        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even++;
            }else{
                odd++;
            }
        }
        int alter=1;
        int parity=nums[0]%2;
        for(int i=1;i<n;i++){
            int currparity=nums[i]%2;
            if(currparity != parity){
                alter++;
                parity=currparity;
            }
        }
        return max({odd,even,alter});
    }
};