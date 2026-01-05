class Solution {
public:
    int minLength(vector<int>& nums, int k){
        int ans=1e9;
        int n=nums.size();
        int i=-1,j=-1;
        int sum=0;
        while(i<n && j<n){
            if(sum<k){
                j++;
                if(j<n) sum+=nums[j];
            }
            else{
                ans=min(ans,j-i+1);
                if(i>-1) sum-=nums[i];
                i++;
            }
        }
        return (ans==1e9)?-1:ans;
    }
};
