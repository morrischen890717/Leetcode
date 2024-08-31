class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i++){
            cnt[target[i]]++;
            cnt[arr[i]]--;
        }
        for(unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            if(it->second)
                return false;
        }
        return true;
    }
};