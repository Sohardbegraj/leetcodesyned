class Solution {
public:
    string answerString(string word, int numFriends) {
        string ans="";
        int n=word.length();
        if(numFriends==1){
            return word;
        }
        int len=n-(numFriends-1);
        for(int i=0;i<n;i++){
            int possible=min(len,n-i);

            ans=max(ans,word.substr(i,possible));
        }
        return ans;
    }
};