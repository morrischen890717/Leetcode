class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        // using Greedy
        // time complexity: O(N + T), where N == clips.size(), T == time, space complexity: O(T)
        // main idea: this problem is similar to Problem 55: Jump Game(https://leetcode.com/problems/jump-game/?envType=featured-list&envId=top-interview-questions?envType=featured-list&envId=top-interview-questions)
        int n = clips.size();
        vector<int> jump(101, 0);
        for(int i = 0; i < n; i++){
            jump[clips[i][0]] = max(jump[clips[i][0]], clips[i][1]);
        }
        int cnt = 0;
        int end = 0, canReach = 0;
        for(int i = 0; i <= time && end < time; i++){
            canReach = max(canReach, jump[i]);
            if(i == end){
                if(end >= canReach)
                    return -1;
                end = canReach;
                cnt++;
            }
        }
        return cnt;
    }
};