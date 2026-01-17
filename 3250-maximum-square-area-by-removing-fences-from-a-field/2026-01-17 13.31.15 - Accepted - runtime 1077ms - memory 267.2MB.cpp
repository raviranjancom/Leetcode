class Solution {
public:
    int mod=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences){
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        unordered_set<int> st;
        // for horizontal
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                st.insert(abs(hFences[i]-hFences[j]));
            }
        }
        // for vertical
        int ans=-1;
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                int x=abs(vFences[i]-vFences[j]);
                if(st.find(x)!=st.end()){
                    ans=max(ans,x);
                }
            }
        }
        return (ans==-1)?-1:(1LL*ans*ans)%mod;
    }
};
