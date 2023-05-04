class Solution {
public:
    string predictPartyVictory(string senate) {
        int len = senate.length();
        deque<char> q;
        for(int i = 0; i < len; i++){
            q.push_back(senate[i]);
        }
        char all_same = '0';
        while(all_same == '0'){
            all_same = q.front();
            int cnt_r = 0, cnt_d = 0;
            int n = q.size();
            for(int i = 0; i < n; i++){
                char cur = q.front();
                q.pop_front();
                if(cur == 'R'){
                    if(cnt_d == 0){
                        cnt_r++;
                    }
                    else{
                        cnt_d--;
                        q.push_back('D');
                        if(all_same != 'D')
                            all_same = '0';
                    }
                }
                else{
                    if(cnt_r == 0){
                        cnt_d++;
                    }
                    else{
                        cnt_r--;
                        q.push_back('R');
                        if(all_same != 'R')
                            all_same = '0';
                    }
                }
            }
            int pop_r = 0;
            while(!q.empty() && cnt_r > 0){
                if(q.front() == 'D'){
                    q.pop_front();
                    cnt_r--;
                    q.push_back('R');
                    if(all_same != 'R')
                        all_same = '0';
                }
                else{
                    q.pop_front();
                    pop_r++;
                }
            }
            int pop_d = 0;
            while(!q.empty() && cnt_d > 0){
                if(q.front() == 'R'){
                    q.pop_front();
                    cnt_d--;
                    q.push_back('D');
                    if(all_same != 'D')
                        all_same = '0';
                }
                else{
                    q.pop_front();
                    pop_d++;
                }
            }
            for(int i = 0; i < pop_r; i++){
                q.push_front('R');
            }
            for(int i = 0; i < pop_d; i++){
                q.push_front('D');
            }
        }
        return (all_same == 'R' ? "Radiant" : "Dire");
    }
};