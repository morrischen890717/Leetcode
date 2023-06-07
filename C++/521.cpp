class Solution {
public:
    int findLUSlength(string a, string b) {
        int len1 = a.length(), len2 = b.length();
        return (a == b ? -1 : max(len1, len2));
    }
};