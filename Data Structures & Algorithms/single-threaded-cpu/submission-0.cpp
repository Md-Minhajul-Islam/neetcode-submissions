class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap1, minHeap2;

        for(int i = 0; i < tasks.size(); i++)
        {
            minHeap1.push({tasks[i][0], tasks[i][1], i});
        }

        int t = 1;
        vector<int> ans;
        while(ans.size() < tasks.size())
        {
            while(!minHeap1.empty() && minHeap1.top()[0] <= t)
            {
                minHeap2.push({minHeap1.top()[1], minHeap1.top()[2]});
                minHeap1.pop();
            }
            
            if(!minHeap2.empty())
            {
                t += minHeap2.top()[0];
                ans.push_back(minHeap2.top()[1]);
                minHeap2.pop();
            }
            else t = minHeap1.top()[0];
        }
        return ans;
    }
};