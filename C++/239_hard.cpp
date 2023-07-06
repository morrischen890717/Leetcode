class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
        using monotonic queue
        time complexity: O(N)
        */
        int n = nums.size();
        vector<int> ans(n - k + 1);
        deque<int> q; // q stores the id in nums which keeps decreasing order of their value
        for(int i = 0; i < n; i++){
            while(!q.empty() && nums[q.back()] < nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            if(i >= k - 1)
                ans[i - (k - 1)] = nums[q.front()]; // maximum value in sliding window
            if(q.front() == i - k + 1) // is going to be out of the range of sliding window
                q.pop_front();
        }
        return ans;
    }
};