class TaskManager {
public:
    map<pair<int,int>,int>  mp;  //    {priority,taskID}-->userId
    unordered_map<int,pair<int ,int>> mp1; //    taskid-->{priority,userid}        
        

    TaskManager(vector<vector<int>>& tasks) {
      for(int i=0;i<tasks.size();i++){
        mp[{tasks[i][2],tasks[i][1]}]=tasks[i][0];
        mp1[tasks[i][1]]={tasks[i][2],tasks[i][0]};
      }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[{priority,taskId}]=userId;
        mp1[taskId]={priority,userId};
    }
    
    void edit(int taskId, int newPriority) {
        int old_priority=mp1[taskId].first;
        int old_userid=mp1[taskId].second;

        mp1[taskId].first=newPriority;
        mp.erase({old_priority,taskId});
        mp[{newPriority,taskId}]=old_userid;
    }
    
    void rmv(int taskId) {
        int old_priority=mp1[taskId].first;
        int old_userid=mp1[taskId].second;

        mp1.erase(taskId);
        mp.erase({old_priority,taskId});
    }
    
    int execTop() {
        if(mp.empty()) return -1;
        int x=mp.rbegin()->first.second;
        int ans=mp.rbegin()->second;
        rmv(x);
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */