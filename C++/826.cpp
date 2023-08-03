class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // using two-pointers and sort()
        // time complexity: O(DlogD + WlogW), where D == difficulty.size() and W == worker.size()
        int ans = 0;
        int n = difficulty.size();
        int maxProfit = 0;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++){
            v[i] = {difficulty[i], profit[i]};
        }
        sort(v.begin(), v.end()); // costs O(DlogD) time
        sort(worker.begin(), worker.end()); // cost O(WlogW) time

        int ptr = 0;
        // costs O(D + W) time
        for(int ability: worker){
            while(ptr < n && v[ptr].first <= ability){
                maxProfit = max(maxProfit, v[ptr].second);
                ptr++;
            }
            ans += maxProfit;
        }
        return ans;
    }
};