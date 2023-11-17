class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int ans = 0, max_id = 0;
        for(int i = 0; i < flips.size(); i++){
            max_id = max(max_id, flips[i]);
            if(max_id == i + 1)
                ans++;
        }
        return ans;
    }
};