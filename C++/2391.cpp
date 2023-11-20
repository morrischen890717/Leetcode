class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // using prefix sum
        int ans = 0;
        int n = garbage.size();
        vector<int> last(3, 0); // 0: G, 1: M, 2: P
        for(int i = 0; i < n; i++){
            ans += garbage[i].length();
            for(char c: garbage[i]){
                if(c == 'G')
                    last[0] = i;
                else if(c == 'M')
                    last[1] = i;
                else if(c == 'P')
                    last[2] = i;
            }
        }
        for(int i = 1; i < travel.size(); i++){
            travel[i] += travel[i - 1];
        }
        for(int pos: last){
            ans += (pos == 0 ? 0 : travel[pos - 1]);
        }
        return ans;
    }
};