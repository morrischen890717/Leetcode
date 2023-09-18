class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        // using Greedy
        // time complexity: O(N), space complexity: O(1)
        int n = arr.size();
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] > arr[i + 1]){
                pair<int, int> max_num = {-1, -1}; // {val, id}
                int j = i + 1;
                while(j < n && arr[i] > arr[j]){
                    if(arr[j] > max_num.first)
                        max_num = {arr[j], j};
                    j++;
                }
                swap(arr[i], arr[max_num.second]);
                return arr;
            }
        }
        return arr;
    }
};