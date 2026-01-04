class Solution {
public:
    int sumFourDivisors(vector<int>& nums){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            bool flag=false;
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    if(flag){
                        sum=0;
                        break;
                    }
                    if(nums[i]/j!=j){
                        sum+=1+nums[i]+j+nums[i]/j;
                        flag=true;
                    }
                }
            }
            ans+=sum;
        }
        return ans;
    }
};
