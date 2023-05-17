class Solution {
public:
    bool isValid(vector<int>& cnt, int k){
        int max_id = max_element(cnt.begin(), cnt.end()) - cnt.begin();
        for(int i = 0; i < 26; i++){
            if(i != max_id)
                k -= cnt[i];
            if(k < 0)
                return false;
        }
        return true;
    }
    int characterReplacement(string s, int k) {
        int len = s.length();
        vector<int> cnt(26, 0);
        int max_len = 0;
        int left = 0, right = 0;
        while(right < len){
            cnt[s[right] - 'A']++;
            if(isValid(cnt, k))
                max_len++;
            else{
                cnt[s[left] - 'A']--;
                left++;
            }
            right++; 
            /*
            we will add 1 to right whether current window is valid or not to let 
            the size of window always == max_len(ans) + 1
            (avoid trying the len which <= max_len, because we knows that a solution with len == max_len is already exists)
            */
        }
        return max_len;
    }
};