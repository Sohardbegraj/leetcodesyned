class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.length();
        stack<char>st;
        int count=1;
        string ans="";
        int i=0;
        while(i<=n){
            st.push(count+'0');
            if(pattern[i] == 'I' || i==n){
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
            }
            count++;
            i++;
        }
        return ans;
    }
};