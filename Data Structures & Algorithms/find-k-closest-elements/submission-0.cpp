class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<pair<int, int>> v;
        for(auto& a: arr) v.push_back({abs(x-a), a});

        sort(v.begin(), v.end(), [&](auto a, auto b){
            if(a.first == b.first) return a.second < b.second;
            else return a.first < b.first;
        });


        vector<int> ans;
        for(auto [d, a]: v)
        {
            k--;
            ans.push_back(a);
            if(k==0) break;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};