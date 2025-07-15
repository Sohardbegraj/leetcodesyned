class Solution {
public:
    bool isValid(string word) {
        int n=word.length();
        bool vowel=false;
        bool consonant=false;
        if(n<3){
            return false;
        }
        for(char ch:word){
            if(!iswalnum(ch)){
                return false;
                break;
            }
            if(isalpha(ch)){
                char el=tolower(ch);
                if(el=='a'|| el=='e'|| el=='i'|| el=='o'|| el=='u'){
                    vowel=true;
                }else{
                    consonant=true;
                }
            }

        }
        return vowel && consonant;

    }
};