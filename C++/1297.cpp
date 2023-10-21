class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        // using sliding window and two-pointers
        // time complexity: O(N)
        int ans = 0;
        int len = s.length();
        vector<int> cnt(26, 0);
        vector<bool> appear(26, false);
        unordered_map<string, int> m;
        int uni_num = 0;
        int l = 0;
        for(int r = 0; r < len; r++){
            if(cnt[s[r] - 'a'] == 0){
                appear[s[r] - 'a'] = true;
                uni_num++;
            }
            cnt[s[r] - 'a']++;
            // we only take the length of minSize(if there is a length > minSize which leads to ans, length == minSize(which is substr of the string with length > minSize) can also leads to ans too)
            while(uni_num > maxLetters || r - l + 1 > minSize){
                cnt[s[l] - 'a']--;
                if(cnt[s[l] - 'a'] == 0){
                    appear[s[l] - 'a'] = false;
                    uni_num--;
                }
                l++;
            }
            if(r - l + 1 == minSize && uni_num <= maxLetters){
                string ss = s.substr(l, r - l + 1);
                m[ss]++;
                ans = max(ans, m[ss]);
            }
        }
        return ans;
    }
};