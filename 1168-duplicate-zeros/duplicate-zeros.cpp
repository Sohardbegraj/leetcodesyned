class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        vector<int>mid;
        for(int i=0;i<n;i++){
            int el=arr[i];
            mid.push_back(el);
            if(el==0){
                mid.push_back(el);
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=mid[i];
        }
    }
};