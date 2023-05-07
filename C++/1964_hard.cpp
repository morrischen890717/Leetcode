class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        /*
        reference: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/solutions/3494489/python-java-c-simple-solution-easy-to-understand/
        */
        int n = obstacles.size();
        vector<int> ans;
        vector<int> increase_subseq(n);
        int len = 0;
        for(int i = 0; i < n; i++){
            int l = 0, r = len - 1; 
            while(l <= r){  // using binary search to find the position where obstacles[i] should insert/replace
                int mid = (l + r) / 2;
                if(obstacles[i] >= increase_subseq[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            increase_subseq[l] = obstacles[i]; // if l == len, then insert to back. Otherwise, replace
            ans.push_back(l + 1);
            if(l == len)
                len++;
        }
        return ans;
    }
};