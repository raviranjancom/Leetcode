class Solution {
public:
    int mod=1e9+7;
    int solve(vector<int>& nums, int &target1, int &target2,int target,int start,map<pair<int,int>,int> &mp){
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
        map<pair<int,int>,int> mp;
        return solve(nums,target1,target2,target1,0,mp);
    }
};