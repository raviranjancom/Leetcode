class Solution {
public:
    unordered_map<int,int> mp;
    int climbStairs(int n){
        if(n<3) return n;
        if(mp.find(n)!=mp.end()) return mp[n];
        return mp[n]=climbStairs(n-1)+climbStairs(n-2);
    }
};
