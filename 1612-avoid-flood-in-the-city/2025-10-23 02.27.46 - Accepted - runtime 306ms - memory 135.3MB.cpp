class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        unordered_map<int,int> mp;  // Non-Zero element --> index
        vector<int> q;  // index of zeros
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                q.push_back(i);
                ans.push_back(1);
            }
            else{
                auto it=mp.find(rains[i]);
                if(it==mp.end()){
                    mp[rains[i]]=i;
                    ans.push_back(-1);
                }
                else{
                    if(q.size()!=0){
                        auto lb=lower_bound(q.begin(),q.end(),mp[rains[i]]);
                        if(lb != q.end()){
                            int x=distance(q.begin(),lb);
                            ans[q[x]]=rains[i];
                            ans.push_back(-1);
                            mp[rains[i]]=i;
                            q.erase(q.begin()+x);
                        }
                        else{
                            return {};
                        }
                    }
                    else{
                        return {};
                    }
                }
            }
        }
        return ans;
    }
};
