class Solution {
public:
    class Compare { // self-defined compare function for priority queue
    public:
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            return (double)a.first / a.second < (double)b.first / b.second;
        }  
    };
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; // pq stores the first k pairs which fractions are smaller than the others
        for(int i = 0; i < n; i++){
            for(int j = n - 1; j > i; j--){
                double val = (double)arr[i] / arr[j];
                if(pq.size() >= k && val > (double)pq.top().first / pq.top().second)
                    break;
                pq.push({arr[i], arr[j]});
                while(pq.size() > k){ // we just need to keep the first k pairs
                    pq.pop();
                }
            }
        }
        return {pq.top().first, pq.top().second};
    }
};