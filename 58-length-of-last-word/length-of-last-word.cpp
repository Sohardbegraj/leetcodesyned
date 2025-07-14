class Solution {
public:
    string trim(const std::string& s) {
        size_t start = s.find_first_not_of(" \t\n\r\f\v");

        if (start == std::string::npos)
            return "";

        size_t end = s.find_last_not_of(" \t\n\r\f\v");

        return s.substr(start, end - start + 1);
    }
    int lengthOfLastWord(string s) { 
        string ans=trim(s); 
        int count=0;
        int lastcount=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=' '){
                count++;
            }else{
                lastcount=count;
                count=0;
            }
        }
        cout<<lastcount;
        return count;
    }
};