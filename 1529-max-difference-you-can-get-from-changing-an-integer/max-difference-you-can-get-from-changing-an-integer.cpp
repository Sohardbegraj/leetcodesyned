class Solution {
public:
    int maxDiff(int num) {
        string minNum = to_string(num);
        string maxNum = to_string(num);
        int n = minNum.length();

        char ch =' ';
        for(int i = 0; i < n; i++) {
            if(maxNum[i] != '9') {
                ch = maxNum[i];
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if(maxNum[i] == ch) {
                maxNum[i] = '9';
            }
        }
        

        if(minNum[0] != '1'){
            char ch=minNum[0];
            for(int i = 0; i < n; i++) {
            if(minNum[i] == ch) {
                minNum[i] = '1';
            }
        }
        }
         else 
        {
            // If first digit is 1, find a digit ≠ 0 or 1 to replace with 0
            for (int i = 1; i < minNum.size(); i++) 
            {
                if (minNum[i] != '0' && minNum[i] != '1') 
                {
                    char to_replace = minNum[i];
                    for (char &ch : minNum) 
                    {
                        if (ch == to_replace)
                        {
                            ch = '0';
                        }
                    }
                    break;
                }
            }
        }
        return (stoi(maxNum) - stoi(minNum));

    }
};