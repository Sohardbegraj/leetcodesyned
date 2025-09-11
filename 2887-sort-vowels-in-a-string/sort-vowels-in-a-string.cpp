class Solution {
public:
    bool isVowel(char ch){
        ch=tolower(ch);
        if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        string t="";
        vector<char>vowels;
        for(char ch:s){
            if(!isVowel(ch)){
                t.push_back(ch);
            }else{
                t.push_back('%');
                vowels.push_back(ch);
            }

        }
        sort(vowels.begin(),vowels.end());

        for(int i=0,j=0; i<t.length();i++){
            if(t[i]=='%'){
                t[i]=vowels[j];
                j++;
            }
        }
        return t;
        
    }
};