class Solution {
public:
    int reverse(int n){
        int ans=0;
        while(n>0){
            ans=ans*10+n%10;
            n=n/10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums){
        int n=nums.size();
        int ans=1e9;
        unordered_map<int,vector<int>> mp;      // element -> index
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        
        for(int i=0;i<n;i++){
            int rev=reverse(nums[i]);
            auto ub=upper_bound(mp[rev].begin(),mp[rev].end(),i);
            if(ub!=mp[rev].end()){
                ans=min(ans,abs(i - *ub));
            }
        }
        return (ans==1e9)?-1:ans;
    }
};
