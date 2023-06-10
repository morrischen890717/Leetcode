class Solution {
public:
    long long computeSum(int n, int index, int target, int maxSum){
        long long leftSum = 0, rightSum = 0;
        leftSum = (target - 1 >= index ? (long long)(2 * target - index - 1) * index / 2 : (long long)target * (target - 1) / 2);
        rightSum = (target >= n - index ? (long long)(2 * target - n + index + 1) * (n - index) / 2 : (long long)(target + 1) * target / 2);
        return leftSum + rightSum;
    }
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n; // do this will make the computation easier (because all elements should be positive(>= 1))
        int l = 1, r = maxSum;
        while(l <= r){ // binary sum
            int mid = l + (r - l) / 2;
            long long sum = computeSum(n, index, mid, maxSum);
            if(sum <= maxSum)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};