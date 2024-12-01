class MinStack {
private:
    vector<int> v;
public:
    MinStack() {
    }
    
    void push(int val) {
        v.push_back(val);
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        if(v.size()==0) return -1;
        else return v.back();
    }
    
    int getMin() {
        int n=v.size(),min=INT_MIN;
        if(n==0) return -1;
        for(int i=0;i<n;i++){
            if(min>v[i]) min=v[i];
        }
        return min;
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