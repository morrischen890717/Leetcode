class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) { // using Boyer–Moore majority vote algorithm, time complexity: O(N), space complexity: O(1)
        int n = nums.size();
        int k = n / 3;
        /*
        because the threshold is n/3, so there should be 2 elements at most in the answer.
        (assume A, B, C are all one of the answer
        => # of A, # of B, # of C > n/3
        => # of total elements >= # of A + # of B + # of C > 3 * (n/3) = n, contradiction)
        */
        int res1 = INT_MAX, res2 = INT_MAX; // res1, res2 means the top 2 majority elements
        int cnt1 = 0, cnt2 = 0;
        vector<int> ans;
        // we divide the elements to three parts, top 2 elements which have the most # (# amybe or maybe not > n/3), and the other elements
        for(int i = 0; i < n; i++){
            if(nums[i] == res1){
                cnt1++;
            }
            else if(nums[i] == res2){
                cnt2++;
            }
            else if(cnt1 > 0 && cnt2 > 0){  // deducting 1 from all three parts will not effect top 2 elements
                cnt1--;
                cnt2--;
            }
            else if(cnt1 <= 0){  // change top 2 elements
                res1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 <= 0){  // change top 2 elements
                res2 = nums[i];
                cnt2 = 1;
            }
        }
        // because we could not sure whether the # of top 2 elements are more than n/3, so we need to check again
        cnt1 = cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == res1)
                cnt1++;
            else if(nums[i] == res2)
                cnt2++;
        }
        if(cnt1 > k)
            ans.push_back(res1);
        if(cnt2 > k)
            ans.push_back(res2);
        return ans;
    }
};