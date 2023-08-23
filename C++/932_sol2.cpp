class Solution {
public:
    vector<int> beautifulArray(int n) {
        // using math and Divide-and-Conquer
        // time complexity: O(NlogN)
        if(n == 1)
            return {1};
        vector<int> res;
        vector<int> left = beautifulArray(n / 2 + n % 2);
        vector<int> right = beautifulArray(n / 2);
        for(int num: left){ // left part should be odd
            res.push_back(num * 2 - 1);
        }
        for(int num: right){ // right part should be even
            res.push_back(num * 2);
        }
        return res;
    }
};