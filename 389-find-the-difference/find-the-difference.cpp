class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=t.length();
        vector<int>ch(26,0);
        for(int i=0;i<n;i++){
            int idx=t[i]-'a';
            ch[idx]++;
        }
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            ch[idx]++;
        }
        for(int i=0;i<ch.size();i++){
            if(ch[i]%2!=0){
                return 'a'+ i;
            }
        }
        return -1;
    }
};