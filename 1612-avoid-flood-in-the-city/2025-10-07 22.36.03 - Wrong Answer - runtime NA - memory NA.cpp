class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans;
        queue<int> q;
        unordered_set<int> st;
        int points=0,n=rains.size();
        for(int i=0;i<n;i++){
            if(rains[i]!=0){
                if(st.find(rains[i])!=st.end()){
                    if(points>0){
                        q.push(rains[i]);
                        points--;
                    }
                    else{
                        return {};
                    }
                }
                else{
                    st.insert(rains[i]);
                }
            }
            else{
                points++;
            }
        }
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                ans.push_back(q.front()); q.pop();
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
