class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(words[i].starts_with(pref)){
                count++;
            }
        }
        return count;
    }
};