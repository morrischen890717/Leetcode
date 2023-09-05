class Solution {
public:
    void add(vector<int>& ans, int k){
        if(k > 1){
            if(ans.size() > 0 && ans.back() == k)
                ans.pop_back();
            else
                ans.push_back(k);
        }
        return;
    }
    void swap(vector<int>& ans, int i, int j){
        add(ans, j + 1);
        add(ans, j - i + 1);
        add(ans, j - i);
        add(ans, j - i - 1);
        add(ans, j - i);
        add(ans, j + 1);
        return;
    }
    vector<int> pancakeSort(vector<int>& arr) {
        // using Greedy
        // time complexity: O(N)
        vector<int> ans;
        int n = arr.size();
        vector<int> pos(n); // pos[val] = position
        for(int i = 0; i < n; i++){
            pos[arr[i] - 1] = i;
        }
        for(int i = 0; i < n; i++){
            int j = pos[i];
            if(i != j){
                swap(ans, i, j);
                pos[arr[i] - 1] = j;
                pos[i] = i;
                arr[j] = arr[i];
                arr[i] = i + 1;
            }
        }
        return ans;
    }
};