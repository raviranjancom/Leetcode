class Solution {
public:
    int minSubarray(vector<int>& nums, int p){
        int n=nums.size();
        long long total=0;
        for(int i=0;i<n;i++){
            total=(total+nums[i])%p;
        }
        if(total==0) return 0;
        unordered_map<int,int> mp; // mod -> idx
        mp[0]=-1;
        long long sum=0;
        int ans=n;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int k=sum%p;
            if(mp.find((k-total+p)%p)!=mp.end()){
                ans=min(ans,i-mp[(k-total+p)%p]);
            }
            mp[k]=i;
        }
        return (ans==n)?-1:ans;
    }
};
