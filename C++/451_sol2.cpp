class Solution {
public:
    string frequencySort(string s) {
        /*
        using bucket sort
        reference: https://leetcode.com/problems/sort-characters-by-frequency/solutions/1503201/c-python-3-solutions-sorting-bucket-sort-o-n-clean-concise/
        time complexity: O(N)
        space complexity: O(N)
        */
        int len = s.length();
        unordered_map<char, int> cnt;
        vector<vector<char>> bucket(len + 1);
        string ans;
        for(int i = 0; i < len; i++){
            cnt[s[i]]++;
        }
        for(auto it = cnt.begin(); it != cnt.end(); it++){
            bucket[it->second].push_back(it->first);
        }
        for(int freq = len; freq >= 1; freq--){
            for(char c: bucket[freq]){
                ans.append(freq, c);
            }
        }
        return ans;
    }
};