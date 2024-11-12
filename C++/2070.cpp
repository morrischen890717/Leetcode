class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // using sort and binary search
        vector<int> ans;
        int n = items.size();
        sort(items.begin(), items.end());
        for(int i = 1; i < n; i++){
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }
        for(int q: queries){
            int l = 0, r = n - 1;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(items[mid][0] <= q)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            if(r < 0)
                ans.push_back(0);
            else
                ans.push_back(items[r][1]);
        }
        return ans;
    }
};