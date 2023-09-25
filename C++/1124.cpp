class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // using unordered_map and prefix sum
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/longest-well-performing-interval/solutions/334565/java-c-python-o-n-solution-life-needs-996-and-669/
        int ans = 0;
        unordered_map<int, int> pos; // first appeared position
        int n = hours.size(), score = 0;
        for(int i = 0; i < n; i++){
            score += hours[i] > 8 ? 1 : -1;
            if(score > 0)
                ans = max(ans, i + 1);
            else{
                if(pos.count(score) == 0)
                    pos[score] = i;
                if(pos.count(score - 1) > 0)
                    ans = max(ans, i - pos[score - 1]); // score - (score - 1) = 1 > 0
            }
        }
        return ans;
    }
};