class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // Time Complexity: O(NlogN)
        int n = intervals.size();
        vector<pair<int, int>> start(n);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            start[i] = {intervals[i][0], i};
        }
        sort(start.begin(), start.end());
        for(int i = 0; i < n; i++){
            int end = intervals[i][1];
            pair<int, int> p = {end, 0};
            /*
            std::lower_bound(): The running time complexity is O(logN) for random-access iterators but for non random-access iterators it is O(N).
            (std::vector<T>::iterator is of a random access category)
            */
            // When lower_bound implements on a sorted vector, the time complexity of it will be O(logN)
            auto it = lower_bound(start.begin(), start.end(), p);
            if(it != start.end())
                ans.push_back(it->second);
            else
                ans.push_back(-1);
        }
        
        return ans;
    }
};