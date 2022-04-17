class StockSpanner {
public:
    stack<pair<int, int>> st;
    int pos;
    StockSpanner() {
        st.push({1e9, -1});
        pos = 0;
    }
    
    int next(int price) {
        while(!st.empty() and st.top().first <= price)  st.pop();
        int prevPos = st.top().second;
        st.push({price, pos});
        return pos++ - prevPos;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */