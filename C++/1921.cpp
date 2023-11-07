class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // using sort()
        // time complexity: O(NlogN), space complexity: O(1)
        int n = dist.size();
        for(int i = 0; i < n; i++){
            dist[i] = dist[i] / speed[i] + (dist[i] % speed[i] ? 1 : 0); // compute time
        }
        sort(dist.begin(), dist.end());
        for(int i = 0; i < n; i++){
            if(dist[i] < i + 1)
                return i;
        }
        return n;
    }
};