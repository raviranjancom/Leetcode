class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=*max_element(begin(nums),end(nums))+k,ans=0;
        vector<int> hash(n+1,0);
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i=1;i<hash.size();i++){
            hash[i]+=hash[i-1];
        }
        for(int i=0;i<hash.size();i++){
            int lb=max(i-k,0);
            int ub=min(i+k,n);

            int total_range=hash[ub]-(lb>0 ? hash[lb-1] : 0);
            int current_freq=hash[i]-(i>0 ? hash[i-1] : 0);
            int possible_range=min(total_range-current_freq,numOperations)+current_freq;
            ans=max(ans,possible_range);
        }
        return ans;
    }
};
