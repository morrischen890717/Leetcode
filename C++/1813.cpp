class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        sentence1 = " " + sentence1 + " ";
        sentence2 = " " + sentence2 + " ";
        int len1 = sentence1.length(), len2 = sentence2.length();
        if(len1 > len2)
            return areSentencesSimilar(sentence2, sentence1);
        int l1 = 0, r1 = len1 - 1, l2 = 0, r2 = len2 - 1;
        int frontSpace = INT_MAX, endSpace = INT_MIN;
        while(l1 < len1 && l2 < len2 && sentence1[l1] == sentence2[l2]){
            if(sentence1[l1] == ' ')
                frontSpace = l1;
            l1++;
            l2++;
        }
        while(r1 >= 0 && r2 >= 0 && sentence1[r1] == sentence2[r2]){
            if(sentence1[r1] == ' ')
                endSpace = r1;
            r1--;
            r2--;
        }
        return frontSpace >= endSpace;
    }
};