class Solution {
public:
    string multiply(string num1, string num2) {
        // main idea: ans[pos] = sum(num1[i] + num2[j]) for all pairs of {i, j} where i >= 0 && i < num1.length() && j >= 0 && j < num2.length() && i + j == pos
        if(num1 == "0" || num2 == "0")
            return "0";
        int n1 = num1.length(), n2 = num2.length();
        int sum = 0;
        string ans;
        for(int pos = 0; pos < n1 + n2 - 1; pos++){
            for(int i = max(0, pos - n2 + 1); i <= min(pos, n1 - 1); i++){
                int j = pos - i;
                int d1 = num1[n1 - 1 - i] - '0', d2 = num2[n2 - 1 - j] - '0';
                sum += d1 * d2;
            }
            ans = to_string(sum % 10) + ans;
            sum /= 10; // carry
        }
        if(sum)
            ans = to_string(sum % 10) + ans;
        return ans;
    }
};