class MyStack {
public:
       queue<int>q;
       queue<int>temp; 
    MyStack() {
    }
    
    void push(int x) {
        if(q.empty()){
            q.push(x);
        }
        else{
            while(!q.empty()){
                temp.push(q.front());
                q.pop();
            }
            q.push(x);
            while(!temp.empty()){
                q.push(temp.front());
                temp.pop();
            }
        }
    }
    
    int pop() {
        int a=q.front();
        q.pop();
        return a;

    }
    
    int top() {
        if(q.empty()){
            return 0;
        }
        int a= q.front();
        return a;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */