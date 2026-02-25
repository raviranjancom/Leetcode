class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return {nums[i],i+1};
            }
        }
        return {-1,-1};
    }
};
