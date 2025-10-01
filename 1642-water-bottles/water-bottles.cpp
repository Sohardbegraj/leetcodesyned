class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int empty = 0;
        int filled = numBottles;

        int ans = 0;

        while(filled > 0){
            filled = numBottles;
            ans += filled;
            empty += filled;


            numBottles = empty / numExchange;
            empty = empty % numExchange;
        }

        return ans;
        
    }
};