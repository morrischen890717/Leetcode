class Solution {
public:
    bool winnerOfGame(string colors) {
        int len = colors.size();
        int mid_a = 0, mid_b = 0;
        for(int i = 1; i < len - 1; i++){
            if(colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A')
                mid_a++;
            else if(colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B')
                mid_b++;
        }
        return mid_a > mid_b;
    }
};