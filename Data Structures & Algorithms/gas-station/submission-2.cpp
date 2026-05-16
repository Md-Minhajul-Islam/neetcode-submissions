class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // if(gas.size() <= 1) return 0;

        int left = 0, right = 0, sum = 0;
        while(left < gas.size())
        {
            int contri = gas[right]-cost[right];
            sum += contri;
            right = (right+1)%gas.size();
            if(sum < 0)
            {
                if(right <= left) break;
                left = right;
                sum = 0;
            }
            else if(left == right) return left;
        }
        return -1;
    }
};
