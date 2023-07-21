class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for(int num: arr){
            int maxNum = num;
            while(!st.empty() && st.top() > num){
                maxNum = max(maxNum, st.top());
                st.pop();
            }
            st.push(maxNum);
        }
        return st.size();
    }
};