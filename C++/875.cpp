class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // using binary search
        // time complexity: O(NlogM), where N == piles.size(), M == maximum number in piles, space complexity: O(1)
        int maxNum = 0;
        for(int pile: piles){
            maxNum = max(maxNum, pile);
        }
        int l = 1, r = maxNum;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int time = 0;
            for(int pile: piles){
                time += pile / mid + (pile % mid ? 1 : 0);
                if(time > h)
                    break;
            }
            if(time > h)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};