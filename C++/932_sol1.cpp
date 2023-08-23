class Solution {
public:
    vector<int> beautifulArray(int n) {
        // using math
        // time complexity: O(N)
        // reference: https://leetcode.com/problems/beautiful-array/solutions/186679/odd-even-pattern-o-n/
        vector<int> ans = {1};
        while(ans.size() < n){
            vector<int> tmp;
            for(int num: ans){ // let left part to be odd
                if(num * 2 - 1 <= n)
                    tmp.push_back(num * 2 - 1);
            }
            for(int num: ans){ // let right part to be even
                if(num * 2 <= n)
                    tmp.push_back(num * 2);
            }
            ans = tmp;
        }
        return ans;
    }
};