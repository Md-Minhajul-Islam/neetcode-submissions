class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        priority_queue<int> maxHeap;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;

        for(int i = 0; i < capital.size(); i++)
        {
            minHeap.push({capital[i], profits[i]});
        }

        for(int i = 0; i < k; i++)
        {
            while(!minHeap.empty() && minHeap.top()[0] <= w)
            {
                maxHeap.push(minHeap.top()[1]);
                minHeap.pop();
            }

            if(maxHeap.empty()) break;

            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};