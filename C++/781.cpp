class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for(int answer: answers){
            cnt[answer]++;
            if(cnt[answer] == answer + 1){
                ans += cnt[answer];
                cnt.erase(answer);
            }
        }
        for(unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            ans += (it->first + 1);
        }
        return ans;
    }
};