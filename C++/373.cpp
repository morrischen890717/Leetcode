class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // reference: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/solutions/84551/simple-java-o-klogk-solution-with-explanation/
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for(int i = 0; i < nums1.size(); i++){
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        int cnt = 0;
        while(cnt < k && !pq.empty()){
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            ans.push_back({nums1[p.second.first], nums2[p.second.second]});
            cnt++;
            if(p.second.second + 1 < nums2.size())
                pq.push({nums1[p.second.first] + nums2[p.second.second + 1], {p.second.first, p.second.second + 1}});
        }
        return ans;
    }
};