class Solution {
public:
    string makeFancyString(string s) {
        int n =s.length();
        string ans="";
        int count=1;
        ans.push_back(s[0]);
        for(int i=1;i<n;i++){
            ans.push_back(s[i]);
            if(s[i]==s[i-1]){
                count++;
            }else{
                count=1;
            }
            if(count>2){
                ans.pop_back();
            }

        }
        return ans;
    }
};