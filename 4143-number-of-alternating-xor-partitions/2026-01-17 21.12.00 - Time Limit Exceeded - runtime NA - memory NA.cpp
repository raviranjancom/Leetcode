class Solution {
public:
    int mod=1e9+7;
    int solve(vector<int>& nums, int &target1, int &target2,int target,int start){
        int n=nums.size();
        if(start==nums.size()){
            return 1;
        }
        int x=0;
        int ans=0;
        for(int i=start;i<n;i++){
            x=(x^nums[i]);
            if(x==target){
                int prevTarget=target;
                target=(target==target1)?target2:target1;
                ans=(ans+solve(nums,target1,target2,target,i+1))%mod;
                target=prevTarget;
            }
        }
        return ans;
    }
    int alternatingXOR(vector<int>& nums, int target1, int target2){
        return solve(nums,target1,target2,target1,0);
    }
};