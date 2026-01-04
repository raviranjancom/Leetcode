class Solution {
public:
    int sumFourDivisors(vector<int>& nums){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    if(nums[i]/j!=j){
                        ans+=1+nums[i]+j+nums[i]/j;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
