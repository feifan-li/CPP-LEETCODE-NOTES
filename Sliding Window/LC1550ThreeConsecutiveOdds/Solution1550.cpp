class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        //numExchange is the exchange rate
        int ans = numBottles;
        int empty = numBottles;
        while(empty/numExchange >= 1){
            ans += empty/numExchange;
            empty = empty/numExchange + empty%numExchange;
        }
        return ans;
    }
};