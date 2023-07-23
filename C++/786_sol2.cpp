class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>> pq; // // pq stores the first k pairs which fractions are smaller than the others
        for(int i = 0; i < n; i++){
            for(int j = n - 1; j > i; j--){
                double val = (double)arr[i] / arr[j];
                if(pq.size() >= k && val > pq.top().first)
                    break;
                pq.push({val, {arr[i], arr[j]}});
                while(pq.size() > k){ // we just need to keep the first k pairs
                    pq.pop();
                }
            }
        }
        return {pq.top().second.first, pq.top().second.second};
    }
};