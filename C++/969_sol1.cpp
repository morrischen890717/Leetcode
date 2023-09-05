class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        // using multiset
        // time complexity: O(NlogN)
        int n = arr.size();
        vector<int> ans;
        multiset<int> s;
        for(int i = 0; i < n; i++){
            multiset<int>::iterator it;
            it = s.upper_bound(arr[i]);
            if(it != s.end()){
                int d = distance(s.begin(), it);
                ans.push_back(i);
                ans.push_back(i + 1);
                if(d > 0){
                    ans.push_back(d + 1);
                    ans.push_back(d);
                }
            }
            s.insert(arr[i]);
        }
        return ans;
    }
};