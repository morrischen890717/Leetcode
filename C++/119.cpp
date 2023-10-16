class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        for(int i = 0; i <= rowIndex; i++){
            vector<int> newSeq(i + 1);
            newSeq[0] = newSeq[i] = 1;
            for(int j = 1; j < i; j++){
                newSeq[j] = prev[j - 1] + prev[j];
            }
            prev = newSeq;
        }
        return prev;
    }
};