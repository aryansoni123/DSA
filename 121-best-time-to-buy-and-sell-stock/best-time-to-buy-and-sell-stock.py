class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        buy = prices[0]
        p = 0

        for i in range(1, len(prices)):
            cost = prices[i] - buy
            # if(prices[i] - buy) > 0:
            #     p = max(p, prices[i]-buy)
            p = max(p, cost)
            buy = min(prices[i], buy)

        return p

        