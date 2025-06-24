class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n= nums.size();
        unordered_set<int> idxset;
        for(int j=0;j<n;j++){
            if(nums[j]==key){
                int start=max(0,j-k);
                int end=min(j+k,n-1);
                for(int i=start;i<=end;i++){
                    idxset.insert(i);
                }
            }
        }
        vector<int>ans(idxset.begin(), idxset.end());
        sort(ans.begin(), ans.end()); // Maintain increasing order
        return ans;
    }
};