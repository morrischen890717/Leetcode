class Solution {
public:
    int candy(vector<int>& ratings) {
        // using Greedy
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/candy/solutions/42769/a-simple-solution/
        int n = ratings.size();
        vector<int> num(n, 1);
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1])
                num[i] = num[i - 1] + 1;
        }
        int ans = num[n - 1];
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1])
                num[i] = max(num[i], num[i + 1] + 1);
            ans += num[i];
        }
        return ans;
    }
};