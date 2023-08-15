class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // using unordered_set
        // time complexity: O(30N)
        // reference: https://leetcode.com/problems/bitwise-ors-of-subarrays/solutions/165881/c-java-python-o-30n/
        unordered_set<int> ans, s;
        for(int num: arr){
            unordered_set<int> cur = {num};
            for(int a: s){
                cur.insert(num | a);
            }
            for(int b: cur){
                ans.insert(b);
            }
            s = cur;
        }
        return ans.size();
    }
};