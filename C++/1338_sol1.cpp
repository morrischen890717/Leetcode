class Solution {
public:
    int minSetSize(vector<int>& arr) {
        // using unordered_map and counting sort
        // time complexity: O(N)
        int n = arr.size();
        unordered_map<int, int> cnt;
        for(int num: arr){
            cnt[num]++;
        }
        vector<int> occurrence(n + 1, 0);
        for(unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            occurrence[it->second]++;
        }
        int remove = n / 2;
        int ans = 0;
        for(int i = n; i >= 0; i--){
            if(occurrence[i] * i >= remove){
                ans += remove / i + (remove % i ? 1 : 0);
                break;
            }
            else{
                ans += occurrence[i];
                remove -= occurrence[i] * i;
            }
        }
        return ans;
    }
};