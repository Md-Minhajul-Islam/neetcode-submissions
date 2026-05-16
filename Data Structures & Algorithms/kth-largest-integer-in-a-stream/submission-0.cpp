class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto& n: nums) pq.push(n);
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > k) pq.pop();
        return pq.top();
    }
};
