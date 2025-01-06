class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.length();
        vector<int> ans(len, 0);
        int cnt = 0, left_cnt = 0, left = 0, right = 0;
        for(int i = 0; i < len; i++){
            if(boxes[i] == '1'){
                cnt++;
                right += i;
            }
        }
        for(int i = 0; i < len; i++){
            ans[i] = left + right;
            if(boxes[i] == '1')
                left_cnt++; // left_cnt stands for # of '1' in the left side of index i
            left += left_cnt;
            right -= (cnt - left_cnt); // cnt - left_cnt -> right_cnt, right_cnt stands for # of '1' in the right side of index i
        }
        return ans;
    }
};