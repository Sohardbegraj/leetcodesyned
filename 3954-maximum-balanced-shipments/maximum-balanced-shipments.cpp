class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n= weight.size();
        if(n==0) return 0;
        int count=0;
        for(int i=1;i<n;i++){
            if(weight[i-1]> weight[i]){
                count++;
                i++;
            }
        }
        return count;
    }
};