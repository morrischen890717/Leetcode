class Solution {
public:
    void wiggleSort(vector<int>& nums) { // time complexity: O(N), space complexity: O(N)
        /*
        reference:
        https://leetcode.com/problems/wiggle-sort-ii/solutions/77678/3-lines-python-with-explanation-proof/
        https://leetcode.com/problems/wiggle-sort-ii/solutions/77682/step-by-step-explanation-of-index-mapping-in-java/
        */
        int n = nums.size();
        vector<int> v(n);
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());  // nth_element() is implemented by quick select algorithm, and the time complexity of nth_element(): O(N)
        int median = nums[n / 2];
        int odd = 1;  // the leftmost odd index
        int even = (n % 2 == 0 ? n - 2 : n - 1);  // the rightmost even index
        for(int i = 0; i < n; i++){
            if(nums[i] > median){   // place the value which is bigger than median
                v[odd] = nums[i];
                odd += 2;
            }
            else if(nums[i] < median){  // place the value which is smaller than median
                v[even] = nums[i];
                even -= 2;
            }
        }
        /*
        the rest elements of vector v which have not been assigned yet will be assigned to the value of median.
        we put duplicate median as far as possible to avoid consecutive medians.
        */
        while(odd < n){
            v[odd] = median;
            odd += 2;
        }
        while(even >= 0){
            v[even] = median;
            even -= 2;
        }
        for(int i = 0; i < n; i++){
            nums[i] = v[i];
        }
        return;
    }
};