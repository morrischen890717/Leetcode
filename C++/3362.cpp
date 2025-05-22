class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        // using priority_queue
        // reference: https://leetcode.com/problems/zero-array-transformation-iii/solutions/6075702/java-c-python-take-the-query-ending-latest/?envType=daily-question&envId=2025-05-22
        int n = nums.size(), nq = queries.size();
        sort(queries.begin(), queries.end());
        priority_queue<int> pq;
        vector<int> end(n + 1, 0);
        int cur = 0, j = 0;
        for(int i = 0; i < n; i++){
            cur -= end[i];
            while(j < nq && queries[j][0] <= i){
                pq.push(queries[j][1]);
                j++;
            }
            while(cur < nums[i]){
                if(pq.empty() || pq.top() < i)
                    return -1;
                end[pq.top() + 1]++;
                pq.pop();
                cur++;
            }
        }
        return pq.size();
    }
};