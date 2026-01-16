// class Solution {
// public:
//     int mod=1e9+7;
//     int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences){
//         sort(hFences.begin(),hFences.end());
//         sort(vFences.begin(),vFences.end());
//         int hmax=1,vmax=1,x=1,y=1;
//         for(int i=1;i<hFences.size();i++){
//             if(hFences[i-1]=hFences[i]-1){
//                 x++;
//             }
//             else{
//                 x=1;
//             }
//             hmax=max(hmax,x);
//         }
//         for(int i=1;i<vFences.size();i++){
//             if(vFences[i-1]=vFences[i]-1){
//                 y++;
//             }
//             else{
//                 y=1;
//             }
//             vmax=max(vmax,y);
//         }
//         int side=min(hmax,vmax);
//         return (side*side)%mod;
//     }
// };
class Solution {
    unordered_set<int> getEdges(vector<int>& fences, int border) {
        unordered_set<int> st;
        fences.push_back(1);
        fences.push_back(border);
        sort(fences.begin(), fences.end());
        for (int i = 0; i < fences.size(); i++) {
            for (int j = i + 1; j < fences.size(); j++) {
                st.insert(fences[j] - fences[i]);
            }
        }
        return st;
    }

public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        auto hEdges = getEdges(hFences, m);
        auto vEdges = getEdges(vFences, n);
        int res = 0;
        for (auto e : hEdges) {
            if (vEdges.contains(e)) {
                res = max(res, e);
            }
        }
        if (res == 0) {
            res = -1;
        } else {
            res = 1ll * res * res % 1000000007;
        }
        return res;
    }
};