class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n1 = word1.size(), n2 = word2.size();
        int wordId1 = 0, wordId2 = 0, charId1 = 0, charId2 = 0;
        while(wordId1 < n1 && wordId2 < n2){
            if(word1[wordId1][charId1] != word2[wordId2][charId2])
                return false;
            charId1++;
            charId2++;
            if(charId1 == word1[wordId1].length()){
                wordId1++;
                charId1 = 0;
            }
            if(charId2 == word2[wordId2].length()){
                wordId2++;
                charId2 = 0;
            }
        }
        return wordId1 == n1 && wordId2 == n2;
    }
};