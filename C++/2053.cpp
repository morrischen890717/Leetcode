class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> cnt;
        for(string s: arr){
            cnt[s]++;
        }
        for(string s: arr){
            if(cnt[s] == 1){
                if(k == 1)
                    return s;
                else
                    k--;
            }
        }
        return "";
    }
};