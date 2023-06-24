class Solution {
public:
    string solveEquation(string equation) {
        equation += "+";
        int len = equation.length();
        int coefficient_x = 0, constant = 0;
        string num;
        int sign = 1;
        for(int i = 0; i < len; i++){
            if(equation[i] == 'x'){
                if(num == "")
                    coefficient_x += sign;
                else if(num == "-")
                    coefficient_x -= sign;
                else
                    coefficient_x += sign * stoi(num);
                num = "";
            }
            else if(equation[i] == '='){
                if(num != "")
                    constant += sign * stoi(num);
                sign = -sign; // move the element which is on the right hand side of '=' to the left hand side
                num = "";
            }
            else if(equation[i] == '+' || equation[i] == '-'){
                if(num != "")
                    constant += sign * stoi(num);
                num = (equation[i] == '-' ? "-" : "");
            }
            else
                num += equation[i];
        }
        if(coefficient_x == 0){
            if(constant == 0)
                return "Infinite solutions";
            else
                return "No solution";
        }
        return "x=" + to_string(-constant/coefficient_x);
    }
};