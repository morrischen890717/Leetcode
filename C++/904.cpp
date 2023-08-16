class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // time complexity: O(N), space complexity: O(1)
        int ans = 0;
        int n = fruits.size();
        int start = 0; // startId
        pair<int, int> fruit1 = {-1, 0}, fruit2 = {-1, 0}; // {type, endId}
        for(int i = 0; i < n; i++){
            if(fruit1.first == -1 || fruits[i] == fruit1.first)
                fruit1 = {fruits[i], i};
            else if(fruit2.first == -1 || fruits[i] == fruit2.first)
                fruit2 = {fruits[i], i};
            else{
                ans = max(ans, i - start);
                if(fruit1.second < fruit2.second){ // which one ends first
                    start = fruit1.second + 1;
                    fruit1 = {fruits[i], i};
                }
                else{
                    start = fruit2.second + 1;
                    fruit2 = {fruits[i], i};
                }
            }
        }
        ans = max(ans, n - start);
        return ans;
    }
};