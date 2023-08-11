class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        // using priority_queue, sort(), and two-pointers
        // time complexity: O(NlogN), space complexity: O(N)
        int n = nums1.size();
        vector<int> ans(n, -1);
        vector<bool> used(n, false);
        sort(nums1.begin(), nums1.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
        for(int i = 0; i < n; i++){
            pq2.push({nums2[i], i});
        }
        for(int i = 0; i < n; i++){
            if(nums1[i] > pq2.top().first){
                ans[pq2.top().second] = nums1[i];
                used[i] = true;
                pq2.pop();
            }
        }
        for(int i = 0, j = 0; i < n; i++){ // two-pointers
            if(ans[i] == -1){
                while(used[j]){
                    j++;
                }
                ans[i] = nums1[j];
                used[j] = true;
            }
        }
        return ans;
    }
};