class MedianFinder {

public:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        mx.push(num);
        if(mx.size() > mn.size()){
            int tmp = mx.top();
            mx.pop();
            mn.push(tmp);
        }
        if(mn.size() > mx.size()){
            int tmp = mn.top();
            mn.pop();
            mx.push(tmp);
        }
    }
    
    double findMedian() {
        if(mx.size() > mn.size()){
            return mx.top();
        }
        else{
            return double(mx.top() + mn.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */