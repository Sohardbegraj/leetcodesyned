class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int minlen=0;
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
            if(mp[ch]>=3){
                mp[ch]-=2;
            }
        }
        for (const auto& pair : mp) {
            minlen += pair.second; 
        }
        return minlen;
    }
};