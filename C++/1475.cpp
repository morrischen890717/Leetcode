class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        int min_val = INT_MAX;
        for(int i = n - 1; i >= 0; i--){
            int tmp = prices[i];
            while(!st.empty() && prices[i] < st.top()){
                st.pop();
            }
            if(!st.empty())
                prices[i] -= st.top();
            st.push(tmp);
        }
        return prices;
    }
};