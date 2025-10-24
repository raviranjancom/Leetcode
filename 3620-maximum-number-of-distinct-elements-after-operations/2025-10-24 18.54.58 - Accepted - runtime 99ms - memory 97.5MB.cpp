class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        nums[0]=nums[0]-k;
        int prev=nums[0],ans=1;
        for(int i=1;i<n;i++){
            if(nums[i]-k>prev){
                nums[i]=nums[i]-k;
                ans++;
                prev=nums[i];
            }
            else if(nums[i]-k<=prev && prev+1<=nums[i]+k && prev+1>=nums[i]-k){
                nums[i]=prev+1;
                prev=nums[i];
                ans++;
            }
        }
        return ans;
    }
};
