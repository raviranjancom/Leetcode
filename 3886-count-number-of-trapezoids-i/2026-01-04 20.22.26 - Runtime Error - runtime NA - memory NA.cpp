class Solution {
public:
    int mod=1e9+7;
    int nCr(int n){
        return n*(n-1)/2;
    }
    int countTrapezoids(vector<vector<int>>& points){
        map<int,int> mp; // y->{count of points at that level}
        int n=points.size();
        int ans=0;
        int prev=0;
        for(int i=0;i<n;i++){
            mp[points[i][1]]++;
        }
        for(auto &it:mp){
            int horizontal=nCr(it.second);
            ans=(ans+horizontal*prev)%mod;
            prev+=horizontal;
        }
        return ans;
    }
};
