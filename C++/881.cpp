class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // using two-pointers, sort(), and binary search
        // time complexity: O(NlogN), space complexity: O(1)
        int ans = 0;
        int n = people.size();
        sort(people.begin(), people.end());
        int right = n;
        for(int i = 0; i < right; i++){
            // find the heaviest person which people[i] can sit with
            int l = i + 1, r = right - 1;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(people[i] + people[mid] > limit)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            // the people in (r, right) can only take the boat alone
            ans += (right - r);
            right = r;
        }
        return ans;
    }
};