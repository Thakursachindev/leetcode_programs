// Solution 1

class MinStack {
public:
vector<int> v;
    MinStack() {
        vector<int> v;
    }
    
    void push(int x) {
        v.push_back(x);
    }
    
    void pop() {
        v.erase(v.begin()+v.size()-1);
    }
    
    int top() {
        //return v[v.size()-1];
        return v.back();
    }
    
    int getMin() {
        return *min_element(v.begin(), v.end());
    }

};


// Solution 2


class MinStack {

public:
    stack<int> st;

    stack<int> min;

    MinStack() { min.push(INT_MAX); }

    void push(int val) {

        if (val <= min.top())

            min.push(val);

        st.push(val);
    }
    void pop() {

        if (st.top() == min.top())
            min.pop();
        st.pop();
    }
    int top() { return st.top(); }
    int getMin() { return min.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
