class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        // using sort and priority_queue
        // time complexity: O(NlogN), space complexity: O(N)
        // reference: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/solutions/141768/detailed-explanation-o-nlogn/?envType=daily-question&envId=2024-05-11
        double ans = DBL_MAX;
        int n = quality.size();
        vector<int> id(n);
        for(int i = 0; i < n; i++){
            id[i] = i;
        }
        sort(id.begin(), id.end(), [&quality, &wage](int& i, int& j){
            return (double)wage[i] / quality[i] < (double)wage[j] / quality[j];
        });
        priority_queue<int> pq;
        int sum = 0;
        for(int i: id){
            sum += quality[i];
            pq.push(quality[i]);
            if(pq.size() == k){
                ans = min(ans, (double)wage[i] / quality[i] * sum);
                sum -= pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};