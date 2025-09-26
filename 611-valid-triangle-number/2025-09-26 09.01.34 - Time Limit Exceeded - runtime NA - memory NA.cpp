class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j] > nums[k] && nums[j]+nums[k] > nums[i] && nums[i]+nums[k] > nums[j] && nums[i]!=0 && nums[j]!=0 && nums[k]!=0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
