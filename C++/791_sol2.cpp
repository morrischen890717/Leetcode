class Cmp { // self-defined compare function/class
private:
    vector<int> pos;
public:
    bool operator() (char& a, char& b){ // operator overlaod
        return pos[a - 'a'] < pos[b - 'a'];
    }
    Cmp(vector<int>& pos){
        this->pos = pos;
    }
};
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> pos(26);
        for(int i = 0; i < order.length(); i++){
            pos[order[i] - 'a'] = i;
        }
        sort(s.begin(), s.end(), Cmp(pos));
        return s;
    }
};