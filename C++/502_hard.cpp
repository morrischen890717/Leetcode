class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // using sort and priority_queue
        // time complexity: O(NlogN), space complexity: O(N)
        // reference: https://leetcode.com/problems/ipo/solutions/3219987/day-54-c-priority-queue-easiest-beginner-friendly-sol/?envType=daily-question&envId=2024-06-15
        int n = profits.size();
        priority_queue<int> pq;
        vector<pair<int, int>> projects;
        for(int i = 0; i < n; i++){
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        for(int i = 0, j = 0; i < k; i++){
            while(j < n && projects[j].first <= w){
                pq.push(projects[j].second);
                j++;
            }
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
            else
                break;
        }
        return w;
    }
};