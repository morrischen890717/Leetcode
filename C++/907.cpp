class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // using monotonic stack
        // time complexity: O(N), space complexity: O(N)
        const int MOD = 1e9 + 7;
        int sum = 0;
        int n = arr.size();
        stack<pair<int, int>> st; // {num, id}
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first >= arr[i]){
                pair<int, int> p = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top().second;
                sum += ((long long)((long long)(i - p.second) * (p.second - left)) % MOD * p.first) % MOD;
                sum %= MOD;
            }
            st.push({arr[i], i});
        }
        while(!st.empty()){
            pair<int, int> p = st.top();
            st.pop();
            int left = st.empty() ? -1 : st.top().second;
            /*
            (n - p.second) is # of elements on the right, (p.second - left) is # of elements on the left
            so we have (n - p.second) * (p.second - left) subarrays (pick one index from left and pick one index from right), 
            and the minimum value in these subarrays is p.first
            */
            sum += ((long long)((long long)(n - p.second) * (p.second - left)) % MOD * p.first) % MOD;
            sum %= MOD;
        }
        return sum;
    }
};