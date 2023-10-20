class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        // using map
        map<int, int> cnt;
        for(int num: nums){
            cnt[num]++;
        }
        for(map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            int count = it->second;
            if(count == 0)
                continue;
            for(int i = it->first; i < it->first + k; i++){
                if(cnt.count(i) == 0 || cnt[i] < count)
                    return false;
                else
                    cnt[i] -= count;
            }
        }
        return true;
    }
};