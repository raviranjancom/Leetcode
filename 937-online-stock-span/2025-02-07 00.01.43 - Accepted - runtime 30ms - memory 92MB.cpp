class StockSpanner {
public:
    stack<pair<int,int>> ds;
    int i;
    StockSpanner() {
        i=-1;
    }
    
    int next(int price) {
        i++;
        int ans;
        while(!ds.empty() && price >= ds.top().first){
            ds.pop();
        }
        if(ds.empty()){
            ans=i-(-1);
        }
        else{
            ans=i - ds.top().second;
        }
        ds.push({price,i});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */