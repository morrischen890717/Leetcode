class Solution {
public:
    int find(vector<int>& parent, int i){
        return parent[i] == i ? i : find(parent, parent[i]);
    }
    void uni(vector<int>& parent, vector<int>& size, int i, int j){
        int parent_i = find(parent, i), parent_j = find(parent, j);
        if(parent_i == parent_j)
            return;
        if(size[parent_i] < size[parent_j]){
            parent[parent_i] = parent_j;
            size[parent_j] += size[parent_i];
        }
        else{
            parent[parent_j] = parent_i;
            size[parent_i] += size[parent_j];
        }
        return;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        // using Union-Find
        // reference: https://leetcode.com/problems/greatest-common-divisor-traversal/solutions/3568567/union-find-in-c-java-and-python/?envType=daily-question&envId=2024-02-25
        int n = nums.size();
        if(n == 1)
            return true;
        unordered_map<int, int> m;
        vector<int> parent(n);
        vector<int> size(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(int i = 0; i < n; i++){
            if(nums[i] == 1)
                return false;
            for(int j = 2; j * j <= nums[i]; j++){
                if(nums[i] % j == 0){
                    if(m.count(j) > 0)
                        uni(parent, size, i, m[j]);
                    else
                        m[j] = i;
                    while(nums[i] % j == 0){
                        nums[i] /= j;
                    }
                }
            }
            if(nums[i] > 1){
                if(m.count(nums[i]) > 0)
                    uni(parent, size, i, m[nums[i]]);
                else
                    m[nums[i]] = i;
            }
        }
        return size[find(parent, 0)] == n;
    }
};