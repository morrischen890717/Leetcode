class Solution {
public:
    string frequencySort(string s) {
        /*
        time complexity: O(N + KlogK), where N is the length of string, K <= 62 is the # of distinct characters
        space complexity: O(N)
        */
        int len = s.length();
        unordered_map<char, int> cnt;
        priority_queue<pair<int, char>> pq;
        string ans;
        for(int i = 0; i < len; i++){
            cnt[s[i]]++;
        }
        for(auto it = cnt.begin(); it != cnt.end(); it++){
            pq.push({it->second, it->first});
        }
        while(!pq.empty()){
            pair<int, char> p = pq.top();
            pq.pop();
            for(int i = 0; i < p.first; i++){
                ans += p.second;
            }
        }
        return ans;
    }
};