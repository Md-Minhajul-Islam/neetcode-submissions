class Solution {
public:
void mergeSort(vector<int>& nums, int l, int r)
    {
        if(l >= r) return;
        int m = l+(r-l)/2;
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);

        vector<int> left, right;
        for(int i = l; i <= m; i++) left.push_back(nums[i]);
        for(int i = m+1; i <= r; i++) right.push_back(nums[i]);

        int i = 0, j = 0, k = l;
        while(i < left.size() && j < right.size())
        {
            if(left[i] <= right[j]) nums[k++] = left[i++];
            else nums[k++] = right[j++];
        }
        while(i < left.size()) nums[k++] = left[i++];
        while(j < right.size()) nums[k++] = right[j++]; 
    }
    void sortColors(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
    }
};