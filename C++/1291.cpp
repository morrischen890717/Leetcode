class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int low_digit_num = 0, high_digit_num = 0;
        int low_tmp = low, high_tmp = high;
        while(low_tmp){
            low_digit_num++;
            low_tmp /= 10;
        }
        while(high_tmp){
            high_digit_num++;
            high_tmp /= 10;
        }
        string s = "123456789";
        for(int len = low_digit_num; len <= high_digit_num; len++){
            for(int l = 0; l + len <= s.length(); l++){
                int num = stoi(s.substr(l, len));
                if(num >= low && num <= high)
                    ans.push_back(num);
            }
        }
        return ans;
    }
};