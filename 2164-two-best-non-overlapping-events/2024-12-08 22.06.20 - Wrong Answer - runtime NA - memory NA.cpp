class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            int t=events[i][2];
            for(int j=i+1;j<n;j++){
                if(events[j][0] <= events[i][1]) continue;
                
                else {
                    t+=events[j][2];
                    ans<t?ans=t:ans=ans;
                    
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans<events[i][2]) ans=events[i][2];
        }
        return ans;
    }
};