class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // using sort and stack
        // time complexity: O(NlogN), space complexity: O(N)
        int n = positions.size();
        vector<int> index(n);
        for(int i = 0; i < n; i++){
            index[i] = i;
        }
        sort(index.begin(), index.end(), [&](int a, int b){
            return positions[a] < positions[b];
        });
        stack<int> st;
        for(int id: index){
            while(!st.empty() && directions[st.top()] == 'R' && directions[id] == 'L'){
                int prev = st.top();
                st.pop();
                if(healths[prev] > healths[id]){
                    healths[prev]--;
                    healths[id] = 0;
                    st.push(prev);
                    break;
                }
                else if(healths[id] > healths[prev]){
                    healths[prev] = 0;
                    healths[id]--;
                }
                else{
                    healths[prev] = healths[id] = 0;
                    break;
                }
            }
            if(healths[id] > 0)
                st.push(id);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(healths[i] > 0)
                ans.push_back(healths[i]);
        }
        return ans;
    }
};