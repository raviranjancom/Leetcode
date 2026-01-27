class Solution {
public:
    int minSubarray(vector<int>& nums, int p){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            nums[i]=nums[i]%p;
            sum+=nums[i];
        }
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        unordered_map<int,int> mp;
        int target=sum%p;
        if(target==0) return 0;
        int ans=1e9;
        for(int i=0;i<n;i++){
            if(target==nums[i]){
                ans=min(ans,i+1);
            }
            else if(mp.find(nums[i]-target)!=mp.end()){
                ans=min(ans,i-mp[nums[i]]);
            }
            mp[nums[i]]=i;
        }
        return (ans==1e9)?-1:ans-1;
    }
};
