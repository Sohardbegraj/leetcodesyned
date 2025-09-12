class Solution {
public:
    bool IsVowel(char ch){
        ch=tolower(ch);
        if(ch=='a'||ch=='e'|| ch=='i' || ch=='o'|| ch=='u' ){
            return true;
        }
        else{
            return false;
        }
    }
    bool doesAliceWin(string s) {
        int n=s.length();
        int vowelcount=0;
        for(char ch:s){
            if( IsVowel(ch)){
                vowelcount++;
            }
        }
        if(vowelcount==0){
            return false;
        }
        return true;
    }
};