class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        /*
        using monotonic stack
        time complexity: O(N)
        this problem is exactly same as Problem 769 (Max Chunks To Make Sorted)
        */
        stack<int> st;
        for(int num: arr){
            int maxNum = num;
            while(!st.empty() && num < st.top()){
                maxNum = max(maxNum, st.top());
                st.pop();
            }
            st.push(maxNum);
        }
        return st.size();
    }
};