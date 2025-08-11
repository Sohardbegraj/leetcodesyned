class Solution {
public:
    const long long M = 1000000007;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long>power;
        string num=bitset<32>(n).to_string();
        int j=0;
        for(int i=num.size()-1;i>=0;i--){
            int el=(num[i]- '0')*(1<<j);
            if(el!=0){
                power.push_back(el);

            }
            j++;

        }
        vector<int>ans;

        for(auto query:queries){
            int left=query[0];
            int right=query[1];
            long long product=1;
            for(int i=left;i<=right;i++){
                product = (product * power[i]) % M;
            }
            ans.push_back(product);
        }
        return ans;

    }
};