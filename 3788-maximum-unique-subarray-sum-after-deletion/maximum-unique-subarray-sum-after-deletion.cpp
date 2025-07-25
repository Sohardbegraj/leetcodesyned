class Solution {
public:
    int maxSum(vector<int>& nums) {
       int n=nums.size();
       if(n==1){
        return nums[0];
       }
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);

        }
        int sum=0;
        int maxi=INT_MIN;
        int neg=INT_MIN;
        for(int s:st){
            if(s>=0){
                sum+=s;
                maxi=max(maxi,sum);
            }
            else{
                neg=max(neg,s);
            }
        }
        
        return max(neg,maxi);
    }
};