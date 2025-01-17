class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int>original(n,0);
        for(int i=0;i<n-1;i++){
            original[i + 1] = derived[i] ^ original[i];

        }
        if(derived[n-1] == original[n-1] ^ original[0]){
            return true;
        }

        original[0]=1;

        for(int i=0;i<n-1;i++){
            original[i + 1] = derived[i] ^ original[i];

        }
        if(derived[n-1] == original[n-1] ^ original[0]){
            return true;
        }
        return false;
    }
};