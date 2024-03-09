class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // using sliding window
        int len1 = s1.length(), len2 = s2.length();
        if(len2 < len1)
            return false;
        vector<int> cnt(26, 0);
        for(char c: s1){
            cnt[c - 'a']++;
        }
        for(int i = 0; i < len2; i++){
            cnt[s2[i] - 'a']--;
            if(i >= len1)
                cnt[s2[i - len1] - 'a']++;
            bool valid = true;
            for(int num: cnt){
                if(num != 0){
                    valid = false;
                    break;
                }
            }
            if(valid)
                return true;
        }
        return false;
    }
};