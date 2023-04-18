class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        string result;
        int i = 0;
        while(i < len1 || i < len2){
            if(i < len1)
                result += word1[i];
            if(i < len2)
                result += word2[i];
            i++;
        }
        return result;
    }
};