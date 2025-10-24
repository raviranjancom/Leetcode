class Solution {
public:
    void solve(vector<int>& nums, vector<int>& hash){
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                ans++;
            }
            else{
                hash.push_back(ans);
                ans=1;
            }
        }
        hash.push_back(ans);
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> hash;
        // creating custom hash (100% my thought)
        solve(nums,hash);
        // checking the value of k
        int ans=0;
        for(int i=1;i<hash.size();i++){
            int x=min(hash[i-1],hash[i]);
            ans=max({ans,x,hash[i-1]/2, hash[i]/2});
        }
        return ans;
    }
};
