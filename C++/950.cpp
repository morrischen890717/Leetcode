class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // using sort() and deque
        // time complexity: O(NlogN), space complexity: O(N)
        // reference: https://leetcode.com/problems/reveal-cards-in-increasing-order/solutions/200515/java-c-python-simulate-the-reversed-process/
        int n = deck.size();
        sort(deck.rbegin(), deck.rend()); // sort by decreasing order
        deque<int> q;
        q.push_back(deck[0]);
        for(int i = 1; i < n; i++){
            q.push_front(q.back());
            q.pop_back();
            q.push_front(deck[i]);
        }
        vector<int> ans(q.begin(), q.end());
        return ans;
    }
};