class Solution {
public:
    int nextGreaterElement(int n) {
        // using monotonic stack
        long long ans = 0;
        vector<int> st;
        for(int i = 0; i < 32 && n; i++){
            int digit = n % 10;
            n /= 10;
            if(!st.empty() && st.back() > digit){
                bool bigger = false; // if the smallest num which larger than digit appear or not
                ans = n * pow(10, i + 1);
                int pos = i - 1;
                for(int num: st){
                    if(num > digit && !bigger){
                        bigger = true;
                        ans += num * pow(10, i);
                        ans += digit * pow(10, pos);
                    }
                    else
                        ans += num * pow(10, pos);
                    pos--;
                }
                return ans > INT_MAX ? -1 : ans;
            }
            else
                st.push_back(digit);
        }
        return -1;
    }
};