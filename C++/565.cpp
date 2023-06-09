class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(visited[i])
                continue;
            int cur = i;
            int len = 0;
            do{ 
                visited[cur] = true;
                len++;
                cur = nums[cur];
            } while(cur != i);
            ans = max(ans, len);
        }
        return ans;
    }
};