class MedianFinder {
public:

    priority_queue<int> firstHalf;
    priority_queue<int ,vector<int>, greater<int>> secondHalf;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(secondHalf.size() == 0 || num <= secondHalf.top())
            firstHalf.push(num);
        else secondHalf.push(num);

        //size() returns unsigned integer type
        // if secondHalf.size() > firstHalf.size()
        // the subtraction may produce a huge positive number due to unsigned underflow
        if((int)firstHalf.size() - (int)secondHalf.size() > 1)
        {
            secondHalf.push(firstHalf.top());
            firstHalf.pop();
        }
        else if(secondHalf.size() > firstHalf.size())
        {
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        }
    }
    
    double findMedian() {
        int n = firstHalf.size();
        int m = secondHalf.size();
        if((n+m)%2) return firstHalf.top();
        else
        {
            return (firstHalf.top()+secondHalf.top())/2.0;
        }
    }
};
