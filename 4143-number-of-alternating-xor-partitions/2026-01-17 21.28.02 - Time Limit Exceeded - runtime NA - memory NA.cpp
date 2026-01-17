class Solution {
public:
    int mod=1e9+7;
    struct str{
        size_t operator()(const pair<int,int> &p)const{
            size_t h1=hash<int>{}(p.first);
            size_t h2=hash<int>{}(p.second);
            return h1^(h2<<1);
        }
    };
    int solve(vector<int>& nums, int &target1, int &target2,int target,int start,unordered_map<pair<int,int>,int,str> &mp){
        int n=nums.size();
        if(start==nums.size()){
            return 1;
        }
        if(mp.find({start,target})!=mp.end()){
            return mp[{start,target}];
        }
        int x=0;
        int ans=0;
        for(int i=start;i<n;i++){
            x=(x^nums[i]);
            if(x==target){
                int prevTarget=target;
                target=(target==target1)?target2:target1;
                ans=(ans+solve(nums,target1,target2,target,i+1,mp))%mod;
                target=prevTarget;
            }
        }
        return mp[{start,target}]=ans;
    }
    int alternatingXOR(vector<int>& nums, int target1, int target2){
        unordered_map<pair<int,int>,int,str> mp;
        return solve(nums,target1,target2,target1,0,mp);
    }
};