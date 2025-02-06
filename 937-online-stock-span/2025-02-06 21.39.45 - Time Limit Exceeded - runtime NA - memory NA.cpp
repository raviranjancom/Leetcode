class StockSpanner {
public:
    stack<int> ds;
    stack<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int v=0;
        ds.push(price);
        while(!ds.empty() && ds.top()<=price){
            st.push(ds.top());
            ds.pop();
            v++;
        }
        while(!st.empty()){
            ds.push(st.top());
            st.pop();
        }
        return v;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
 