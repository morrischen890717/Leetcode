class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while(i < nums1.size() || j < nums2.size()){
            int id1 = i < nums1.size() ? nums1[i][0] : INT_MAX, id2 = j < nums2.size() ? nums2[j][0] : INT_MAX;
            if(id1 == id2)
                ans.push_back({id1, nums1[i++][1] + nums2[j++][1]});
            else if(id1 < id2)
                ans.push_back({id1, nums1[i++][1]});
            else
                ans.push_back({id2, nums2[j++][1]});
        }
        return ans;
    }
};