class Solution {
public:
    string less_than_thousand(vector<string>& less_than_twenty, vector<string>& tens, vector<string>& thousands, int num){
        string res = "";
        if(num >= 100)
            res = less_than_twenty[num / 100] + " " + "Hundred" + " " + less_than_thousand(less_than_twenty, tens, thousands, num % 100);
        else if(num >= 20)
            res = tens[num / 10] + " " + less_than_twenty[num % 10];
        else
            res = less_than_twenty[num];
        if(!res.empty() && res.back() == ' ')
            res.pop_back();
        return res;
    }
    string numberToWords(int num) {
        // reference: https://leetcode.com/problems/integer-to-english-words/solutions/70625/my-clean-java-solution-very-easy-to-understand/?envType=daily-question&envId=2024-08-07
        if(num == 0)
            return "Zero";
        string ans = "";
        vector<string> less_than_twenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        int i = 0;
        while(num){
            if(num % 1000)
                ans = less_than_thousand(less_than_twenty, tens, thousands, num % 1000) + " " + thousands[i] + " " + ans;
            num /= 1000;
            i++;
        }
        while(!ans.empty() && ans.back() == ' ')
            ans.pop_back();
        return ans;
    }
};