class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // using monotonic stack and sort()
        // time complexity: O(NlogN), space complexity: O(N)
        int n = position.size();
        vector<pair<int, double>> car(n); // {position, time}
        for(int i = 0; i < n; i++){
            car[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
        sort(car.begin(), car.end());
        stack<double> st;
        for(pair<int, double> p: car){
            while(!st.empty() && p.second >= st.top()){
                st.pop();
            }
            st.push(p.second);
        }
        return st.size();
    }
};