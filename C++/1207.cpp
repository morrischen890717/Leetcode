class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // using unordered_map and bucket sort
        // time complexity: O(N), space complexity: O(N)
        int n = arr.size();
        unordered_map<int, int> cnt;
        for(int num: arr){
            cnt[num]++;
        }
        vector<int> bucket(n + 1, 0);
        for(unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            bucket[it->second]++;
        }
        for(int num: bucket){
            if(num != 0 && num != 1)
                return false;
        }
        return true;
    }
};