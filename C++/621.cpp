class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
        using Greedy
        reference: https://leetcode.com/problems/task-scheduler/solutions/104500/java-o-n-time-o-1-space-1-pass-no-sorting-solution-with-detailed-explanation/
        */
        int num = tasks.size();
        vector<int> cnt(26, 0);
        int max = 0;
        int maxCount = 0;
        for(int task: tasks){
            cnt[task - 'A']++;
            if(max < cnt[task - 'A']){
                max = cnt[task - 'A'];
                maxCount = 1;
            }
            else if(max == cnt[task - 'A']){
                maxCount++;
            }
        }
        // (max - 1) stands for # of part, (n + 1 - maxCount) stands for the empty seat, (num - max * maxCount) stands for the remaining tasks
        int idle = (n + 1 - maxCount) * (max - 1) - (num - max * maxCount);
        if(idle < 0)
            idle = 0;
        return num + idle;
    }
};