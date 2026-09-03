class StockSpanner {
    stack<int> st;
    vector<int> prices;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int day = 0;

        if(st.empty()){
            st.push(prices.size());
            prices.push_back(price);
            return 1;
        } else{
            while(!st.empty() && prices[st.top()] <= price) st.pop();

            if(!st.empty()){
                day = prices.size() - st.top();
            } else{
                day = prices.size() + 1;
            }

            // st.push(price);
            st.push(prices.size());
            prices.push_back(price);
        }

        return day;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */