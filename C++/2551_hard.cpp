class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        /*
        using quick select (nth_element)
        time complexity: O(N)
        reference: 
        https://leetcode.com/problems/put-marbles-in-bags/solutions/3734537/beat-100-o-n-most-optimal-solution-no-sorting/
        https://leetcode.com/problems/put-marbles-in-bags/solutions/3111736/java-c-python-3-approachs-best-o-n/
        */
        int n = weights.size();
        long long ans = 0;
        for(int i = 0; i < n - 1; i++){
            weights[i] += weights[i + 1]; // weights[i] stands for the sum of the boundary
        }
        weights.pop_back();
        n--;
        nth_element(weights.begin(), weights.begin() + k - 1, weights.end());
        for(int i = 0; i < k - 1; i++){
            ans -= weights[i];
        }
        nth_element(weights.begin(), weights.begin() + n - k, weights.end());
        for(int i = n - 1; i > n - k; i--){
            ans += weights[i];
        }
        return ans;
    }
};