class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int len1 = s.length(), len2 = goal.length();
        if(len1 != len2)
            return false;
        vector<int> cnt(26, 0);
        int id1 = -1, id2 = -1;
        for(int i = 0; i < len1; i++){
            cnt[s[i] - 'a']++;
            if(s[i] != goal[i]){
                if(id1 == -1)
                    id1 = i;
                else if(id2 == -1)
                    id2 = i;
                else
                    return false;
            }
        }
        if(id1 != -1 && id2 != -1)
            return s[id1] == goal[id2] && s[id2] == goal[id1];
        if((id1 == -1 && id2 != -1) || (id1 != -1 && id2 == -1))
            return false;
        for(int num: cnt){
            if(num > 1)
                return true;
        }
        return false;
    }
};