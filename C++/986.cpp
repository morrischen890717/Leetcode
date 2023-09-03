class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // using two-pointers
        // time complexity: O(N1 + N2), where N1 = firstList.length() and N2 = secondList.length()
        vector<vector<int>> ans;
        int n1 = firstList.size(), n2 = secondList.size();
        int ptr_A = 0, ptr_B = 0;
        while(ptr_A < n1 && ptr_B < n2){
            int left = max(firstList[ptr_A][0], secondList[ptr_B][0]);
            int right = min(firstList[ptr_A][1], secondList[ptr_B][1]);
            if(left <= right)
                ans.push_back({left, right});
            if(firstList[ptr_A][1] < secondList[ptr_B][1])
                ptr_A++;
            else
                ptr_B++;
        }
        return ans;
    }
};