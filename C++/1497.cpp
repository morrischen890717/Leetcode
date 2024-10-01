class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> cnt(k, 0);
        for(int num: arr){
            if(num >= 0)
                cnt[num % k]++;
            else
                cnt[(k - (-num % k)) % k]++;
        }
        for(int i = 1; i < k / 2 + k % 2; i++){
            if(cnt[i] != cnt[k - i])
                return false;
        }
        if(k % 2 == 0 && cnt[k / 2] % 2)
            return false;
        return true;
    }
};