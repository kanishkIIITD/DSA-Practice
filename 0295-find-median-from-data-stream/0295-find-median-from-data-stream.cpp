class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>,  greater<int>> minHeap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }
        int maxSize = maxHeap.size();
        int minSize = minHeap.size();
        double median = findMedian();
        if(minSize == maxSize){
            if(num > median)
                minHeap.push(num);
            else
                maxHeap.push(num);
        }
        else if(minSize > maxSize){
            if(num < median)
                maxHeap.push(num);
            else{
                int minTop = minHeap.top(); minHeap.pop();
                minHeap.push(num);
                maxHeap.push(minTop);
            }
        }
        else{
            if(num > median)
                minHeap.push(num);
            else{
                int maxTop = maxHeap.top(); maxHeap.pop();
                minHeap.push(maxTop);
                maxHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        int maxSize = maxHeap.size();
        int minSize = minHeap.size();
        if(minSize == maxSize)
            return (minHeap.top() + maxHeap.top()) / 2.0;
        else if(minSize > maxSize)
            return minHeap.top();
        else
            return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */