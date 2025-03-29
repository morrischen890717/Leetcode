class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int primeFactor(int num){
        int res = 0;
        for(int i = 2; i < sqrt(num); i++){
            if(num % i == 0){
                res++;
                while(num % i == 0){
                    num /= i;
                }
            }
        }
        if(num > 1)
            res++;
        return res;
    }
    long long qpow(long long val, long long cnt){
        long long res = 1;
        while(cnt){
            if((cnt & 1) == 1){
                res *= val;
                res %= MOD;
            }
            val *= val;
            val %= MOD;
            cnt >>= 1;
        }
        return res;
    }
    int maximumScore(vector<int>& nums, int k) {
        // using monotonic stack
        // reference: https://leetcode.com/problems/apply-operations-to-maximize-score/solutions/6591433/efficient-solution-using-arrays-and-stacks-greedy-monotonic-stack/?envType=daily-question&envId=2025-03-29
        int n = nums.size();
        vector<vector<int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({nums[i], i, primeFactor(nums[i])});
        }
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        for(vector<int>& arr: v){
            while(!st.empty() && v[st.top()][2] < arr[2]){
                st.pop();
            }
            if(!st.empty())
                left[arr[1]] = st.top();
            st.push(arr[1]);
        }
        st = stack<int> ();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && v[st.top()][2] <= v[i][2]){
                st.pop();
            }
            if(!st.empty())
                right[v[i][1]] = st.top();
            st.push(v[i][1]);
        }
        sort(v.rbegin(), v.rend());
        long long ans = 1;
        for(vector<int>& arr: v){
            int val = arr[0], i = arr[1], l = left[i], r = right[i];
            long long cnt = (long long)(i - l) * (r - i);
            if(cnt < k){
                ans *= qpow((long long)val, cnt);
                ans %= MOD;
                k -= cnt;
            }
            else{
                ans *= qpow((long long)val, k);
                ans %= MOD;
                break;
            }
        }
        return ans;
    }
};