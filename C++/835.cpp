class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        // time complexity: O(N^2 + A + B), where N == img1.size() == img2.size(), A == # of 1 in img1, B == # of 1 in img2
        // reference: https://leetcode.com/problems/image-overlap/solutions/130623/c-java-python-straight-forward/
        int n = img1.size();
        int ans = 0;
        vector<pair<int, int>> v1, v2;
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j])
                    v1.push_back({i, j});
                if(img2[i][j])
                    v2.push_back({i, j});
            }
        }
        for(pair<int, int> p1: v1){
            for(pair<int, int> p2: v2){
                cnt[(p1.first - p2.first) * 100 + (p1.second - p2.second)]++;
            }
        }
        for(unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            ans = max(ans, it->second);
        }
        return ans;
    }
};