class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0], profit = 0;

        for(int i = 1; i<n; i++){
            int cost = prices[i] - buy;
            profit = max(profit, cost);
            buy = min(buy, prices[i]);
        }

        return profit;
    }
};