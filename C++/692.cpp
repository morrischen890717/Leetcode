class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        /*
        time complexity: O(Nlog(K))
        space complexity: O(N)
        */
        unordered_map<string, int> cnt;
        for(string& word: words){
            cnt[word]++;
        }
        priority_queue<pair<int, string>> pq; // {-count, word}        
        for(unordered_map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            pq.push({-it->second, it->first});
            while(pq.size() > k)
                pq.pop();
        }
        vector<string> ans(k);
        for(int i = k - 1; i >= 0; i--){ // from back to front
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};