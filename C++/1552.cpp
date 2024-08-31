class Solution {
public:
    int cnt(vector<int>& position, int d){
        int n = position.size();
        int base = position[0], count = 0;
        for(int i = 0; i < n; i++){
            if(position[i] - base >= d){
                count++;
                base = position[i];
            }
        }
        return count;
    }
    int maxDistance(vector<int>& position, int m) {
        // using sort and binary search
        // reference: https://leetcode.com/problems/magnetic-force-between-two-balls/solutions/794070/python-c-binary-search-solution-with-explanation-and-similar-questions/?envType=daily-question&envId=2024-06-20
        int n = position.size();
        sort(position.begin(), position.end());
        int l = 0, r = (position.back() - position[0]) / (m - 1);
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(cnt(position, mid) >= m - 1)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
};