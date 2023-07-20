class MedianFinder {
public:
    // time complexity: addNum: O(logN), findMedian: O(1)
    // if minHeap.size() == k, then maxHeap.size() == k or k+1
    priority_queue<int> maxHeap; // maxHeap, stores the smaller values
    priority_queue<int, vector<int>, greater<int>> minHeap; // minHeap, stores the larger values
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(!minHeap.empty() && num > minHeap.top())
            minHeap.push(num);
        else
            maxHeap.push(num);
        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        return;
    }
    
    double findMedian() {
        if(maxHeap.empty())
            return 1e-5;
        else if((maxHeap.size() + minHeap.size()) % 2)
            return (double)maxHeap.top();
        return ((double)maxHeap.top() + minHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */