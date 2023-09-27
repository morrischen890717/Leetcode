class Solution {
public:
    void add(string& ans, char c, int num){
        for(int i = 0; i < num; i++){
            ans += c;
        }
        return;
    }
    string alphabetBoardPath(string target) {
        string ans;
        int len = target.size();
        int prev_x = 0, prev_y = 0;
        for(int i = 0; i < len; i++){
            int x = (target[i] - 'a') / 5, y = (target[i] - 'a') % 5;
            int dis_x = x - prev_x, dis_y = y - prev_y;
            if(prev_x == 5 && prev_y == 0 && target[i] != 'z'){ // if the previous char is 'z' and current char is not 'z'
                prev_x--;
                dis_x++;
                ans += 'U';
            }
            if(dis_y > 0)
                add(ans, 'R', dis_y);
            else
                add(ans, 'L', -dis_y);
            if(dis_x > 0)
                add(ans, 'D', dis_x);
            else
                add(ans, 'U', -dis_x);
            ans += '!';
            prev_x = x;
            prev_y = y;
        }
        return ans;
    }
};