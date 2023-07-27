class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        /*
        using sort() and Greedy
        time complexity: O(NlogN), where N = batteries.size()
        reference: https://leetcode.com/problems/maximum-running-time-of-n-computers/solutions/1692939/java-c-python-sort-solution-with-explanation-o-mlogm/
        */
        int size = batteries.size();
        sort(batteries.begin(), batteries.end());
        long long sum = 0;
        for(int battery: batteries){
            sum += battery;
        }
        int i = 0;
        while(batteries[size - 1 - i] > sum / (n - i)){
            sum -= batteries[size - 1 - i];
            i++;
        }
        return sum / (n - i);
    }
};