class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int sum=0,ans=0,carry=1,pos=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0 && carry==1){
                sum+=nums[i]+carry;
                carry=0;
                pos=i;
            }
            else if(nums[i]==0 && carry==0){
                sum=i-1-pos;
                sum+=1;
                pos=i;
            }
            else{
                sum+=nums[i];
            }
            ans=max(ans,sum);
        }
        return ans-1;
    }
};
