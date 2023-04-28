class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n - 1;
        int ans = 0;
        while(l <= r){  // binary search
            int mid = (l + r) / 2;
            if(citations[mid] >= (n - mid)){
                ans = n - mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};