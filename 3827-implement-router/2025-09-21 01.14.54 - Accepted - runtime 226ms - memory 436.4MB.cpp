class Router {
public:
    int memory=0;
    queue<vector<int>> q;
    set<vector<int>> st;
    unordered_map<int, vector<int>> mp;     // Destination ---> {Timestamp}

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
            mp[destination].push_back(timestamp);
            if(q.size()>memory){
                forwardPacket();
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
        mp[q.front()[1]].erase(mp[q.front()[1]].begin());
        q.pop();

        return res;
    }
    
    int getCount(int destination, int startTime, int endTime) {

        auto check=mp.find(destination);
        if(check == mp.end() || check->second.empty()){
            return 0;
        }
        int ans=0;
        int lw=lower_bound(begin(check->second) ,end(check->second), startTime) - begin(check->second);
        int hw=upper_bound(begin(check->second), end(check->second), endTime) - begin(check->second);

        return hw - lw;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */