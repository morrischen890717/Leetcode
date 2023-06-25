void operator+= (vector<int> &a, const vector<int> &b){ // operator overloading
    int n = a.size();
    for(int i = 0; i < n; i++){
        a[i] += b[i];
    }
    return;
}
void operator-= (vector<int> &a, const vector<int> &b){ // operator overloading
    int n = a.size();
    for(int i = 0; i < n; i++){
        a[i] -= b[i];
    }
    return;
}
bool operator>= (const vector<int> &a, const vector<int> &b){
    int n = a.size();
    for(int i = 0; i < n; i++){
        if(a[i] < b[i])
            return false;
    }
    return true;
}
class Solution {
public:
    friend void operator+=(vector<int> &a, const vector<int> &b); // operator overloading
    friend void operator-=(vector<int> &a, const vector<int> &b); // operator overloading
    friend bool operator>=(const vector<int> &a, const vector<int> &b); // operator overloading
    bool empty(vector<int>& needs){
        int n = needs.size();
        for(int i = 0; i < n; i++){
            if(needs[i] != 0)
                return false;
        }
        return true;
    }
    int dfs(vector<int> &price, int n, vector<vector<int>> &special, vector<int> &needs, int &cost, int cur){
        if(empty(needs))
            return cur;
        for(int i = 0; i < special.size(); i++){ // use special
            if(cur + special[i].back() >= cost || !(needs >= special[i])) // pruning
                continue;
            needs -= special[i];
            cost = min(cost, dfs(price, n, special, needs, cost, cur + special[i].back()));
            needs += special[i];
        }
        for(int i = 0; i < n; i++){ // do not use special
            cur += price[i] * needs[i];
        }
        cost = min(cost, cur);
        return cost;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        /*
        using DFS
        reference: https://leetcode.com/problems/shopping-offers/solutions/105252/concise-c-dfs-solution-6ms/
        */
        int n = price.size();
        int cost = 0, cur = 0;
        for(int i = 0; i < n; i++){
            cost += price[i] * needs[i];
        }
        return dfs(price, n, special, needs, cost, 0);
    }
};