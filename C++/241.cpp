class Solution {
public:
    int calculate(int num1, int num2, char op){
        if(op == '+')
            return num1 + num2;
        else if(op == '-')
            return num1 - num2;
        else if(op == '*')
            return num1 * num2;
        return INT_MIN;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int n = expression.length();
        bool no_operator = 1;
        for(int i = 0; i < n; i++){
            if(!isdigit(expression[i])){
                no_operator = 0;
                vector<int> left = diffWaysToCompute(expression.substr(0, i));  // substr from index 0 ~ i - 1
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));    // substr from index i + 1 to the end of the string
                for(int j = 0; j < left.size(); j++){
                    for(int k = 0; k < right.size(); k++){
                        ans.push_back(calculate(left[j], right[k], expression[i]));
                    }
                }
            }
        }
        if(no_operator)
            ans.push_back(stoi(expression));
        return ans;
    }
};