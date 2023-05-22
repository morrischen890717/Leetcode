class Solution {
public:
    string originalDigits(string s) {
        int len = s.length();
        unordered_map<char, int> cnt;
        vector<int> num(10, 0);
        string ans;
        for(int i = 0; i < len; i++){
            cnt[s[i]]++;
        }
        int tmp;
        tmp = cnt['z'];
        num[0] += tmp;
        cnt['z'] -= tmp;
        cnt['e'] -= tmp;
        cnt['r'] -= tmp;
        cnt['o'] -= tmp;
        tmp = cnt['w'];
        num[2] += tmp;
        cnt['t'] -= tmp;
        cnt['w'] -= tmp;
        cnt['o'] -= tmp;
        tmp = cnt['u'];
        num[4] += tmp;
        cnt['f'] -= tmp;
        cnt['o'] -= tmp;
        cnt['u'] -= tmp;
        cnt['r'] -= tmp;
        tmp = cnt['f'];
        num[5] += tmp;
        cnt['f'] -= tmp;
        cnt['i'] -= tmp;
        cnt['v'] -= tmp;
        cnt['e'] -= tmp;
        tmp = cnt['x'];
        num[6] += tmp;
        cnt['s'] -= tmp;
        cnt['i'] -= tmp;
        cnt['x'] -= tmp;
        tmp = cnt['v'];
        num[7] += tmp;
        cnt['s'] -= tmp;
        cnt['e'] -= tmp;
        cnt['v'] -= tmp;
        cnt['e'] -= tmp;
        cnt['n'] -= tmp;
        tmp = cnt['g'];
        num[8] += tmp;
        cnt['e'] -= tmp;
        cnt['i'] -= tmp;
        cnt['g'] -= tmp;
        cnt['h'] -= tmp;
        cnt['t'] -= tmp;
        tmp = cnt['i'];
        num[9] += tmp;
        cnt['n'] -= tmp;
        cnt['i'] -= tmp;
        cnt['n'] -= tmp;
        cnt['e'] -= tmp;
        tmp = cnt['o'];
        num[1] += tmp;
        cnt['o'] -= tmp;
        cnt['n'] -= tmp;
        cnt['e'] -= tmp;
        tmp = cnt['r'];
        num[3] += tmp;
        cnt['t'] -= tmp;
        cnt['h'] -= tmp;
        cnt['r'] -= tmp;
        cnt['e'] -= tmp;
        cnt['e'] -= tmp;
        for(int i = 0; i < 10; i++){
            ans.append(num[i], '0' + i);
        }
        return ans;
    }
};