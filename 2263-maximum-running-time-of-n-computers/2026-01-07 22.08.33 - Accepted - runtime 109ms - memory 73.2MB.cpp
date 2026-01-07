class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries){
        sort(batteries.rbegin(),batteries.rend());
        long long balance=accumulate(batteries.begin()+n, batteries.end(),0LL);
        map<int,long long> mp; // value->frq
        for(int i=0;i<n;i++){
            mp[batteries[i]]++;
        }
        auto it=mp.begin();
        while(next(it)!=mp.end()){
            auto curr=it;
            auto next_node=next(it);
            long long diff=(next_node->first - curr->first)*curr->second;
            if(diff>balance){
                return curr->first+(balance/curr->second);
            }
            else{
                balance-=diff;
                mp[next_node->first]+=curr->second;
                mp.erase(curr);
                it=mp.begin();
            }
        }
        return mp.begin()->first+(balance/n);
    }
};
