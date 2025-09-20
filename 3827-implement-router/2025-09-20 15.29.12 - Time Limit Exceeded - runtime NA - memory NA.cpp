class Router {
public:
    int memory=0;
    queue<vector<int>> q;
    set<vector<int>> st;
    Router(int memoryLimit) {
        memory=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        int prev_size=st.size();
        st.insert({source,destination,timestamp});

        if(prev_size==st.size()){
            return false;
        }
        else{
            q.push({source,destination,timestamp});
            if(q.size()>memory){
                st.erase({q.front()[0], q.front()[1], q.front()[2]});
                q.pop();
            }
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()){
            return {};
        }
        vector<int> res={q.front()[0], q.front()[1], q.front()[2]};
        st.erase({q.front()[0], q.front()[1], q.front()[2]});
        q.pop();

        return res;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int ans=0;
        for(auto it:st){
            int target_destination=it[1];
            int time=it[2];

            if(destination==target_destination && (time>=startTime && time<=endTime)) ans++;
        }
        return ans;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
