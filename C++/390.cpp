class Solution {
public:
    int solve(int n, bool remove_from_left){
        int index;
        if(n == 1)
            index = 0;
        else if(n % 2 == 1){ // remove from left or right are the same
            index = 2 * solve(n / 2, !remove_from_left) + 1;
        }
        else{
            if(remove_from_left == true){
                index = 2 * solve(n / 2, !remove_from_left) + 1;
            }
            else{
                index = 2 * solve(n / 2, !remove_from_left);
            }
        }
        return index;
    }

    int lastRemaining(int n) {
        return solve(n, true) + 1; // solve() return the index in [1, n], so we should add 1 to get the answer
    }
};