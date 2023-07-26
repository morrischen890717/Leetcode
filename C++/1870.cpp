class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // using binary search
        int n = dist.size();
        int min = 1, max = 1e7; // based on the mentioned constraint of the problem
        while(min <= max){
            int mid = min + (max - min) / 2;
            double time = 0;
            for(int i = 0; i < n - 1; i++){
                time += ceil((double)dist[i] / mid);
            }
            time += (double)dist[n - 1] / mid;
            if(time <= hour)
                max = mid - 1;
            else
                min = mid + 1;
        }
        return min == 1e7 + 1 ? -1 : min;
    }
};