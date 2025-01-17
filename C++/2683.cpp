class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int state = 0;
        for(int num: derived){
            state ^= num;
        }
        return state == 0;
    }
};