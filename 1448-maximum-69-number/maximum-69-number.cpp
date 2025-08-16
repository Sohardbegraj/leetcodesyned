class Solution {
public:
    int maximum69Number (int num) {
       stack<int>st;
       while(num>0){
        int digit=num%10;
        st.push(digit);
        num=num/10;
       }
        num = 0;
        bool changed = false;
        int place = pow(10, st.size() - 1);

        while (!st.empty()) {
            int digit = st.top();
            st.pop();

            if (!changed && digit == 6) {
                digit = 9;
                changed = true;
            }

            num += digit * place;
            place /= 10;
        }

        return num;
    }
};