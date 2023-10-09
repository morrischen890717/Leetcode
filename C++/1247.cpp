class Solution {
public:
    int minimumSwap(string s1, string s2) {
        // using math and Greedy
        int len = s1.length();
        int x_y = 0, y_x = 0; // x_y => s1[i] == 'x' && s2[i] == 'y', y_x => s1[i] == 'y' && s2[i] == 'x'
        for(int i = 0; i < len; i++){
            if(s1[i] == 'x' && s2[i] == 'y')
                x_y++;
            else if(s1[i] == 'y' && s2[i] == 'x')
                y_x++;
        }
        return (x_y % 2) ^ (y_x % 2) ? -1 :  x_y / 2 + y_x / 2 + 2 * (x_y % 2);
    }
};