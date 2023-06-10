class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if(len2 < len1)
            return false;
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);
        for(int i = 0; i < len1; i++){
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        int l = 0, r = len1 - 1;
        cnt2[s2[r] - 'a']--;
        while(r < len2){
            cnt2[s2[r] - 'a']++;
            bool same = true;
            for(int i = 0; i < 26; i++){
                if(cnt1[i] != cnt2[i]){
                    same = false;
                    break;
                }
            }
            if(same)
                return true;
            cnt2[s2[l] - 'a']--;
            l++;
            r++;
        }
        return false;
    }
};