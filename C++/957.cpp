class Solution {
public:
    int cells2Int(vector<int>& cells){
        int res = 0;
        for(int i = 0; i < cells.size(); i++){
            if(cells[i])
                res |= (1 << i);
        }
        return res;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        // using unordered_map
        // reference: https://leetcode.com/problems/prison-cells-after-n-days/solutions/205684/java-python-find-the-loop-or-mod-14/
        unordered_map<int, int> m;
        for(; n > 0; n--){
            vector<int> newCells(8, 0);
            for(int j = 1; j < 7; j++){
                newCells[j] = cells[j - 1] == cells[j + 1] ? 1 : 0;
            }
            int res = cells2Int(newCells);
            if(m.count(res) > 0){
                cout << m[res] << " " << n << '\n';
                n %= (m[res] - n);
                break;
            }
            else
                m[res] = n;
            cells = newCells;
        }
        for(; n > 0; n--){
            vector<int> newCells(8, 0);
            for(int j = 1; j < 7; j++){
                newCells[j] = cells[j - 1] == cells[j + 1] ? 1 : 0;
            }
            cells = newCells;
        }
        return cells;
    }
};