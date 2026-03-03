class Solution {
public:
    unordered_map<int,int> mp;
    bool solve(vector<int>& stones,int idx,int n,int cost){
        if(idx==n-1) return true;
        if(mp.find(stones[idx]+cost)!=mp.end() && idx<mp[stones[idx]+cost]){
            return solve(stones,mp[stones[idx]+cost],n,cost-1)+
            solve(stones,mp[stones[idx]+cost],n,cost)+
            solve(stones,mp[stones[idx]+cost],n,cost+1);
        }
        return false;
    }
    bool canCross(vector<int>& stones){
        int n=stones.size();
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        return solve(stones,0,n,1);
    }
};
