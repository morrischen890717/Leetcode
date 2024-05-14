class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;
        int n = happiness.size();
        sort(happiness.begin(), happiness.end(), [](int& a, int& b){
            return a > b;
        });
        for(int i = 0; i < k; i++){
            sum += max(0, happiness[i] - i);
        }
        return sum;
    }
};