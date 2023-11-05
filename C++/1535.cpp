class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        // using Greedy
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/find-the-winner-of-an-array-game/solutions/768007/java-c-python-one-pass-o-1-space/
        int max_num = arr[0], win = 0;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > max_num){
                max_num = arr[i];
                win = 0;
            }
            win++;
            if(win == k)
                return max_num;
        }
        return max_num;
    }
};