class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        // using unordered_map
        // reference: https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/solutions/6658286/o-n-o-n-k-o-n-log-n-example-walkthrough-c-python-java/?envType=daily-question&envId=2025-04-17
        int ans = 0;
        int n = nums.size();
        unordered_map<int, vector<int>> m1;
        for(int i = 0; i < n; i++){
            m1[nums[i]].push_back(i);
        }
        vector<int> divisors;
        for(int i = 1; i * i <= k; i++){
            if(k % i == 0){
                divisors.push_back(i);
                if(i * i != k)
                    divisors.push_back(k / i);
            }
        }
        for(unordered_map<int, vector<int>>::iterator it = m1.begin(); it != m1.end(); it++){
            int val = it->first;
            unordered_map<int, int> m2;
            for(int pos: it->second){
                int g = gcd(pos, k);
                ans += m2[k / g];
                for(int d: divisors){
                    if(pos % d == 0)
                        m2[d]++;
                }
            }
        }
        return ans;
    }
};