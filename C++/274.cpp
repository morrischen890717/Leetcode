class Solution {
public:
    int hIndex(vector<int>& citations) {    // time complexity: O(N)
        int n = citations.size();
        vector<int> cnt(1001, 0);
        int num = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            cnt[citations[i]]++;
        }
        for(int i = 0; i <= n; i++){
            if(n - num >= i)
                ans = i;
            else
                break;
            num += cnt[i];
        }
        return ans;
    }
};