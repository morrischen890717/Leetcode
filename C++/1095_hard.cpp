/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int find_peak(int n, MountainArray &mountainArr){
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int mid_val = mountainArr.get(mid);
            int left_val = mid == 0 ? INT_MIN : mountainArr.get(mid - 1), right_val = mid == n - 1 ? INT_MIN : mountainArr.get(mid + 1);
            if(left_val < mid_val && mid_val > right_val)
                return mid;
            else if(left_val < mid_val && mid_val < right_val)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
    int find_target(int target, MountainArray &mountainArr, int l, int r, bool left_or_right){
        while(l <= r){
            int mid = l + (r - l) / 2;
            int mid_val = mountainArr.get(mid);
            if(mid_val == target)
                return mid;
            else if(!left_or_right){ // left side of peak
                if(mid_val < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else{ // right side of peak
                if(mid_val < target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = find_peak(n, mountainArr);
        if(mountainArr.get(peak) == target)
            return peak;
        int find_left = find_target(target, mountainArr, 0, peak - 1, false); // find target from left side
        if(find_left != -1)
            return find_left;
        return find_target(target, mountainArr, peak + 1, n - 1, true); // find target from right side
    }
};