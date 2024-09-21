class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/lexicographical-numbers/solutions/5813956/interviewers-expect-iterative-approach-lets-understand/?envType=daily-question&envId=2024-09-21
        vector<int> ans;
        int cur = 1;
        while(ans.size() < n){
            ans.push_back(cur);
            if(cur * 10 <= n)
                cur *= 10;
            else{
                while(cur % 10 == 9 || cur == n){
                    cur /= 10;
                }
                cur++;
            }
        }
        return ans;
    }
};