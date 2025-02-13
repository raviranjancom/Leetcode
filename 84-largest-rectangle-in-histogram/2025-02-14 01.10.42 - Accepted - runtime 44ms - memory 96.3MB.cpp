class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<pair<int,int>> ds,st;
        vector<int> nse,pse;
        for(int i=n-1;i>=0;i--){
            while(!ds.empty() && ds.top().first >= heights[i]){
                ds.pop();
            }
            if(!ds.empty()){
                nse.push_back(ds.top().second);
            }
            else{
                nse.push_back(n);
            }
            ds.push({heights[i],i});
        }
        reverse(nse.begin(), nse.end());
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                pse.push_back(st.top().second);
            }
            else{
                pse.push_back(-1);
            }
            st.push({heights[i],i});
        }

        int ans=INT_MIN,m=INT_MIN;
        for(int i=0;i<n;i++){
            m=heights[i]*((nse[i]-i)+(i-pse[i])-1);
            ans=max(ans,m);
        }
        return ans;
    }
};
