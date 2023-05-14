class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        /*
        reference: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/solutions/91049/java-o-n-solution-using-bit-manipulation-and-hashmap/?orderBy=most_votes
        */
        int n = nums.size();
        int max_xor = 0;
        int mask = 0;
        for(int i = 31; i >= 0; i--){
            unordered_map<int, bool> appear;
            mask |= (1 << i);
            for(int j = 0; j < n; j++){
                int left_part = nums[j] & mask;
                appear[left_part] = true; // nums[j] & mask is the left part of nums[j]
            }
            int new_try = max_xor | (1 << i);
            for(auto& it: appear){
                int left_part = it.first;
                int anothernum = left_part ^ new_try; // if a ^ b = c, then a ^ c = b
                if(appear.count(anothernum) > 0){
                    max_xor = new_try;
                    break;
                }
            }
        }
        return max_xor;
    }
};