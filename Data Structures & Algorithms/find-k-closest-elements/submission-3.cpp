class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int l = 0, r = k-1;
        while(r+1 < arr.size())
        {
            if(abs(arr[r+1]-x) < abs(arr[l]-x)) l++, r++;
            else if(abs(arr[r+1]-x) == abs(arr[l]-x) && arr[r] == arr[l]) l++, r++;
            else break; 
        }
        vector<int> v;
        for(int i = l; i <= r; i++) v.push_back(arr[i]);
        return v; 
    }
};