class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        buy = prices[0]
        p = 0

        n = len(prices)

        for i in range(1, n):
            cost = prices[i] - buy
            p = max(p, cost)
            buy = min(prices[i], buy)

        return p

        