class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>>st;
    int next(int price) {
        if(st.empty() ){
            st.push({price,1});
            return 1;
        }
        int days=1;
        while(!st.empty()&&price>=st.top().first){
            days+=st.top().second;
            st.pop();
        }
        st.push({price,days});
        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */