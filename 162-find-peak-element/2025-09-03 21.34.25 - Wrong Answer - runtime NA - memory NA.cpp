class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if((mid==0 && nums[0]>nums[1]) || (mid==n-1 && nums[n-1]>nums[n-2])){
                return mid;
            }
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            if(nums[mid-1] > nums[mid+1]){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
};