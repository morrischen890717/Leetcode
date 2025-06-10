class Solution {
public:
    int maxDifference(string s) {
        int len = s.length();
        vector<int> freq(26, 0);
        for(char c: s){
            freq[c - 'a']++;
        }
        int odd = 0, even = INT_MAX;
        for(int i = 0; i < 26; i++){
            if(freq[i] == 0)
                continue;
            if(freq[i] % 2)
                odd = max(odd, freq[i]);
            else
                even = min(even, freq[i]);
        }
        return odd - even;
    }
};