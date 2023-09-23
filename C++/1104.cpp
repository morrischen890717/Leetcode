class Solution {
public:
    int convert(int label, int h){
        int num = pow(2, h - 2);
        return 2 * num - (label - num + 1);
    }
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int h = 0, tmp = label;
        while(tmp){
            h++;
            tmp /= 2;
        }
        while(h){
            ans.push_back(label);
            label = convert(label / 2, h);
            h--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};