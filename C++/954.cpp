class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        // using map and Greedy
        int n = arr.size();
        map<int, int> cnt;
        for(int num: arr){
            cnt[num]++;
        }
        for(map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            if(!it->second)
                continue;
            if(it->first < 0 && it->first % 2)
                return false;
            if(it->first < 0){
                if(cnt[it->first / 2] < it->second)
                    return false;
                cnt[it->first / 2] -= it->second;
            }
            else if(it->first == 0){
                if(it->second % 2)
                    return false;
            }
            else{
                if(cnt[it->first * 2] < it->second)
                    return false;
                cnt[it->first * 2] -= it->second;
            }
        }
        return true;
    }
};