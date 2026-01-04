class Solution {
public:
    int mod=1e9+7;
    long long nCr(int n){
        return (1ll*n*(n-1))/(1ll*2);
    }
    int countTrapezoids(vector<vector<int>>& points){
        map<int,int> mp; // y->{count of points at that level}
        int n=points.size();
        long long ans=0;
        int prev=0;
        for(int i=0;i<n;i++){
            mp[points[i][1]]++;
        }
        for(auto &it:mp){
            int horizontal=nCr(it.second);
            ans=(1ll*ans+1ll*horizontal*prev)%mod;
            prev=(prev+horizontal)%mod;
        }
        return ans;
    }
};
