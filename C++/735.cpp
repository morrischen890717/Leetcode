class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int asteroid: asteroids){
            bool exploded = false;
            while(!st.empty() && st.top() > 0 && asteroid < 0 && !exploded){
                if(abs(st.top()) < abs(asteroid))
                    st.pop();
                else if(abs(st.top()) == abs(asteroid)){
                    st.pop();
                    exploded = true;
                }
                else
                    exploded = true;
            }
            if(!exploded)
                st.push(asteroid);
        }
        vector<int> ans(st.size());
        for(int i = st.size() - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};