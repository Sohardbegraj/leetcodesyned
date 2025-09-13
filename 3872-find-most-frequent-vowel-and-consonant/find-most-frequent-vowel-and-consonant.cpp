class Solution {
public:
bool IsVowel(char ch){
    if(ch=='a'|| ch=='e'|| ch=='i'||ch=='o'|| ch=='u'){
        return true;
    }
    return false;

}
    int maxFreqSum(string s) {
        int n=s.length();
        vector<int>alphabhet(26,0);
        vector<int>vowel(26,0);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(IsVowel(s[i])){
                vowel[idx]++;
            }else{
                alphabhet[idx]++;
            }
        }
        int maxi=0;
        for(int s:alphabhet){
            maxi=max(maxi,s);
        }
        int maxi_v=0;
        for(int v:vowel){
            maxi_v=max(maxi_v,v);
        }
    return maxi+maxi_v;
    }
};