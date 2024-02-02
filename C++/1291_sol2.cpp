class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // using BFS
        // reference: https://leetcode.com/problems/sequential-digits/solutions/451862/c-bfs/?envType=daily-question&envId=2024-02-02
        vector<int> ans;
        queue<int> q;
        for(int i = 1; i <= 9; i++){
            q.push(i);
        }
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int num = q.front();
                q.pop();
                if(num >= low && num <= high)
                    ans.push_back(num);
                if(num > high)
                    continue;
                int digit = num % 10;
                if(digit + 1 <= 9)
                    q.push(num * 10 + digit + 1);
            }
        }
        return ans;
    }
};