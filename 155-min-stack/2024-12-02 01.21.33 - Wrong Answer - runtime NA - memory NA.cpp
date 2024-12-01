class MinStack {
private:
    vector<int> v;
    vector<int> min;

public:
    MinStack() { }
    
    void push(int val) {
        v.push_back(val);
        min.push_back(val);
        sort(min.begin(),min.end());
    }
    
    void pop() {
        erase(min, v[v.size()-1]);
        v.pop_back();
        sort(min.begin(),min.end());
    }
    
    int top() {
        if(v.size()==0) return -1;
        else return v.back();
    }
    
    int getMin() {
        int m;
        if(v.size()==0) return -1;
        return min[0];
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */