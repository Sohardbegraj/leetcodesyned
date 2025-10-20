class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n=operations.size();
        int x=0;
        for(string s:operations){
            if(s=="++X"|| s=="X++"){
                x++;
            }
            else if(s=="--X"|| s=="X--"){
                x--;
            }
        }
    return x;
    }
};