class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            int s=INT_MAX,l=INT_MIN;
            for(int j=i;j<n;j++){
                if(s>nums[j]){
                    s=nums[j];
                }
                if(l<nums[j]){
                    l=nums[j];
                }
                ans+=l-s;
            }
            
        }
        return ans;
    }
};
