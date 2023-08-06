class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // using map
        // time complexity: O(NlogM + M(groupSize * logM)), where N == hand.size() and M == cnt.size() (# of different cards)
        int n = hand.size();
        map<int, int> cnt;
        for(int card: hand){ // costs O(NlogM) time
            cnt[card]++;
        }
        for(map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            int val = it->first, num = it->second;
            if(num == 0)
                continue;
            for(int i = val; i < val + groupSize; i++){
                if(!cnt.count(i) || cnt[i] < num)
                    return false;
                cnt[i] -= num;
            }
        }
        return true;
    }
};