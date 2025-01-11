class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        if(n<k){
            return false;
        } 
        vector<int>arr(26,0);
        for(char ch:s){
            arr[ch-'a']++;
        }
        int oddcount=0;
        for(int i=0;i<26;i++){
            if(arr[i]%2!=0){
                oddcount++;
            }
        }
       return oddcount<=k;
    }
};