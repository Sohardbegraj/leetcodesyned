class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int count=0;
        unordered_map<int,int>mp;
        vector<int> result(n,0);
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            if(mp[A[i]]==2){
                count++;
            }
            mp[B[i]]++;
            if(mp[B[i]]==2){
                count++;
            }
            result[i]=count;
        }
        return result;
    }
};