class MinStack {
public:
    vector<int> st;
    vector<int> minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        if(minSt.empty() || minSt.back() >= val) minSt.push_back(val);
    }
    
    void pop() {
        if(minSt.back() == st.back()) minSt.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minSt.back();
    }
};
