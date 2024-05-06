class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        int n = people.size();
        sort(people.begin(), people.end());
        for(int l = 0, r = n - 1; l <= r; l++){
            while(l < r && people[l] + people[r] > limit){
                r--;
                ans++;
            }
            ans++;
            r--;
        }
        return ans;
    }
};