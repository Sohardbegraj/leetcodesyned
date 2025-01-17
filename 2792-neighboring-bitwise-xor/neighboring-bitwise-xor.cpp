class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        int result=0;
        for(int i=0;i<n;i++){
            result^=derived[i];
        }
        if(result==0){
            return true;
        }
        return false;;
    }
};