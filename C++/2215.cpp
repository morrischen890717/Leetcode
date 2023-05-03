class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, bool> m;
        vector<vector<int>> ans(2);
        
        for(int i = 0; i < n1; i++){
            m[nums1[i]] = true;
        }    
        for(int i = 0; i < n2; i++){
            if(m.count(nums2[i]) == 0)
                ans[1].push_back(nums2[i]);
            m[nums2[i]] = false;
        }
        for(unordered_map<int, bool>::iterator it = m.begin(); it != m.end(); it++){
            if(it->second)
                ans[0].push_back(it->first);
        }
        return ans;
    }
};