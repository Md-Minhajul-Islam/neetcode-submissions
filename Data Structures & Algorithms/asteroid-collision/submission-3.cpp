class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> st;
        for(int i = 0; i < asteroids.size(); i++)
        {
            if(asteroids[i] > 0 || st.empty() || st.back() < 0) 
            {
                st.push_back(asteroids[i]);
                continue;
            }
            while(!st.empty() && st.back() > 0 && st.back() < -1*asteroids[i]) st.pop_back();

            if(st.empty() || st.back() < 0) st.push_back(asteroids[i]);
            else if(st.back() == -1*asteroids[i]) st.pop_back();
        }
        return st;
    }
};