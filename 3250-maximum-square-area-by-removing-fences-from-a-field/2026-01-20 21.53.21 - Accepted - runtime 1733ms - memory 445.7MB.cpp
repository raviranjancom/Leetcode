class Solution {
public:
    int mod=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences){
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        unordered_set<int> st1,st2;
        // for horizontal
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                st1.insert(abs(hFences[i]-hFences[j]));
            }
        }
        // for vertical
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                st2.insert(abs(vFences[i]-vFences[j]));
            }
        }
        int ans=-1;
        for(auto &it:st1){
            if(st2.find(it)!=st2.end()){
                ans=max(ans,it);
            }
        }
        return (ans==-1)?-1:(1LL*ans*ans)%mod;
    }
};
