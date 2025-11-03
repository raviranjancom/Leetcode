class Solution {
public:
    int minCost(string colors, vector<int>& neededTime){
        int n=colors.size();
        vector<pair<char,int>> st;
        int ans=0;
        st.push_back({colors[0],neededTime[0]});
        for(int i=1;i<n;i++){
            auto prev=st.back();
            if(prev.first==colors[i]){
                if(prev.second<neededTime[i]){
                    ans+=prev.second;
                    st.pop_back();
                    st.push_back({colors[i],neededTime[i]});
                }
                else{
                    ans+=neededTime[i];
                }
            }
            else{
                st.push_back({colors[i],neededTime[i]});
            }
        }
        return ans;
    }
};
