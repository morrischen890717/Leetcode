class StockSpanner {
private:
    stack<pair<int, int>> st; // {price, consecutive days}
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        // using monotonic stack
        int span = 1;
        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */