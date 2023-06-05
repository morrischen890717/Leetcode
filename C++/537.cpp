class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        vector<int> v1;
        vector<int> v2;
        char *d = "+i";
        // split num1
        char *s1 = new char[len1 + 1];  // char array
        strcpy(s1, num1.c_str()); // convert num1 into char array so that strtok could be used
        char *p1 = strtok(s1, d);
        while (p1 != NULL) {
            v1.push_back(stoi(p1));
            p1 = strtok(NULL, d);		   
        }
        // spilt num2
        char *s2 = new char[len2 + 1];  // char array
        strcpy(s2, num2.c_str()); // convert num2 into char array so that strtok could be used
        char *p2 = strtok(s2, d);
        while (p2 != NULL) {
            v2.push_back(stoi(p2));
            p2 = strtok(NULL, d);		   
        }

        int real = v1[0] * v2[0] - v1[1] * v2[1];
        int imaginary = v1[0] * v2[1] + v1[1] * v2[0];
        return to_string(real) + "+" + to_string(imaginary) + "i";
    }
};