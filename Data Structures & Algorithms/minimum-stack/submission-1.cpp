class MinStack {
public:
    stack<int>st;
    stack<int>st2;
   int minelement=INT_MAX; 
    MinStack() {
        
    }
    
    void push(int val) {
       st.push(val);

        if (st2.empty()) {
            st2.push(val);
        }
        else {
            st2.push(min(val, st2.top()));
        }
    }
    
    void pop() {
        st.pop();
        st2.pop();
    }
    
    int top() {
        return st.top();

    }
    
    int getMin() {
        return st2.top();
    }
};
