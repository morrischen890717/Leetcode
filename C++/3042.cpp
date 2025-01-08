class Solution {
public:
    bool isPrefixAndSuffix(string& s1, string& s2){
        int len1 = s1.length(), len2 = s2.length();
        if(len1 > len2)
            return false;
        for(int i = 0; i < len1; i++){
            if(s1[i] != s2[i] || s1[i] != s2[len2 - len1 + i])
                return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for(int j = 0; j < n; j++){
            for(int i = 0; i < j; i++){
                if(isPrefixAndSuffix(words[i], words[j]))
                    ans++;
            }
        }
        return ans;
    }
};