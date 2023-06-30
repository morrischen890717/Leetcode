class Solution {
public:
    bool isPossible(vector<int>& nums) {
        /*
        using Greedy
        time complexity: O(N), space complexity: O(1)
        reference: https://leetcode.com/problems/split-array-into-consecutive-subsequences/solutions/106495/java-o-n-time-o-1-space-solution-greedily-extending-shorter-subsequence/
        */
        int n = nums.size();
        /*
        c1, c2, c3 stand for the number of consecutive subsequences ending at cur with length of 1, length of 2 and length >= 3
        p1, p2, p3 stand for the number of consecutive subsequences ending at prev with length of 1, length of 2 and length >= 3
        */
        int p1, p2, p3, c1, c2, c3;
        p1 = p2 = p3 = c1 = c2 = c3 = 0;
        int cur, prev = -10000;
        for(int i = 0; i < n; p1 = c1, p2 = c2, p3 = c3, prev = cur){
            cur = nums[i];
            int cnt = 0;
            while(i < n && nums[i] == cur){
                cnt++;
                i++;
            }
            if(cur != prev + 1){
                if(p1 || p2)
                    return false;
                c1 = cnt;
                c2 = c3 = 0;   
            }
            else{
                if(cnt < p1 + p2)
                    return false;
                c2 = p1;
                c3 = p2 + min(p3, cnt - (p1 + p2));
                c1 = max(0, cnt - (p1 + p2 + p3));
            }
        }
        return p1 == 0 && p2 == 0;
    }
};