class Solution {
public:
    bool isRobotBounded(string instructions) {
        // using math
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/robot-bounded-in-circle/solutions/290856/java-c-python-let-chopper-help-explain/
        // main idea: https://imgur.com/Lu7aik1
        int len = instructions.length();
        vector<int> dirs = {0, 1, 0, -1, 0};
        int dir = 0;
        int x = 0, y = 0;
        for(char c: instructions){
            if(c == 'R')
                dir = (dir + 1) % 4;
            else if(c == 'L')
                dir = (dir + 3) % 4;
            else{
                x += dirs[dir];
                y += dirs[dir + 1];
            }
        }
        return x == 0 && y == 0 || dir > 0;
    }
};