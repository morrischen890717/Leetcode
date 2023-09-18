class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // using sliding window
        // time complexity: O(N), space complexity: O(1)
        int n = customers.size();
        int satisfied = 0, more_satisfied = 0, max_more_satisfied = 0;
        for(int i = 0; i < n; i++){
            satisfied += grumpy[i] ? 0 : customers[i];
            more_satisfied += grumpy[i] ? customers[i] : 0;
            if(i >= minutes){
                more_satisfied -= grumpy[i - minutes] ? customers[i - minutes] : 0;
            }
            max_more_satisfied = max(max_more_satisfied, more_satisfied);
        }
        return satisfied + max_more_satisfied;
    }
};