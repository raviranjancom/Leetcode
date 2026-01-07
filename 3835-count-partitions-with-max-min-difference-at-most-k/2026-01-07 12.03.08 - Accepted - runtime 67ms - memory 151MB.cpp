class Solution {
public:
    int countPartitions(vector<int>& nums, int k){
        int n=nums.size();
        deque<int> minDq,maxDq;
        int mod=1e9+7;
        vector<int> dp(n+1,0);
        vector<int> prefix(n+1,0);
        
        dp[0]=1;
        prefix[0]=1;
        int i=0,j=0;
        while(i<n && j<n){
            while(!minDq.empty() && nums[j]<nums[minDq.back()]){
                minDq.pop_back();
            }
            minDq.push_back(j);
            while(!maxDq.empty() && nums[j]>nums[maxDq.back()]){
                maxDq.pop_back();
            }
            maxDq.push_back(j);

            while(nums[maxDq.front()]-nums[minDq.front()]>k){
                i++;
                if(!maxDq.empty() && maxDq.front()<i) maxDq.pop_front();
                if(!minDq.empty() && minDq.front()<i) minDq.pop_front();
                
            }
            dp[j+1]=(prefix[j]-(i>0?prefix[i-1]:0)+mod)%mod;
            prefix[j+1]=(prefix[j]+dp[j+1])%mod;
            j++;
        }
        return dp[n];
    }
};
