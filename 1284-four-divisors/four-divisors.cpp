class Solution {
public:
    vector<int>solve(int n){
        vector<int>ans;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
            ans.push_back(i);
            if (i != n / i)
                ans.push_back(n / i);
            }
        }
        return ans;
    }
    int sumFourDivisors(vector<int>& nums) {
       int n=nums.size();
       int sum=0;
       for(int i=0;i<n;i++){
            int el=nums[i];
            vector<int> ans= solve(el);
            if(ans.size()==4){
                for(int i=0;i<ans.size();i++){
                    sum+=ans[i];
                }
            }
       } 
       return sum;
    }
};