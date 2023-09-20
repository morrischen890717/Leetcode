class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        // using math
        // reference: https://leetcode.com/problems/adding-two-negabinary-numbers/solutions/303751/c-python-convert-from-base-2-addition/
        // main idea: https://imgur.com/8OKSmg2
        int n1 = arr1.size(), n2 = arr2.size();
        vector<int> ans;
        int carry = 0;
        for(int i = 0; i < n1 || i < n2 || carry; i++){
            if(i < n1)
                carry += arr1[n1 - 1 - i];
            if(i < n2)
                carry += arr2[n2 - 1 - i];
            ans.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        for(int i = ans.size() - 1; i >= 1 && ans[i] == 0; i--){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};