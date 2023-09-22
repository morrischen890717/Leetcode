class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int n = count.size();
        int min_num = INT_MAX, max_num = INT_MIN, cnt = 0, most_cnt = INT_MIN, mode = -1;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(count[i] > 0){
                min_num = min(min_num, i);
                max_num = max(max_num, i);
                sum += (long long)i * count[i];
                cnt += count[i];
                if(count[i] > most_cnt){
                    most_cnt = count[i];
                    mode = i;
                }
            }
        }
        double median = -1.0, median_cnt = 0;
        for(int i = 0; i < n; i++){
            median_cnt += count[i];
            if(cnt % 2 && median_cnt >= cnt / 2 + cnt % 2){
                median = (double)i;
                break;
            }
            else if(median_cnt == cnt / 2 && median == -1.0)
                median = (double)i;
            else if(median_cnt > cnt / 2){
                median = median == -1.0 ? i : (double)(median + i) / 2;
                break;
            }
        }
        return {(double)min_num, (double)max_num, (double)sum / cnt, (double)median, (double)mode};
    }
};