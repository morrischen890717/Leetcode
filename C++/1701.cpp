class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long long cur_time = 0, wait = 0;
        for(vector<int>& customer: customers){
            cur_time = (customer[0] > cur_time ? customer[0] : cur_time) + customer[1];
            wait += cur_time - customer[0];
        }
        return (double)wait / n;
    }
};