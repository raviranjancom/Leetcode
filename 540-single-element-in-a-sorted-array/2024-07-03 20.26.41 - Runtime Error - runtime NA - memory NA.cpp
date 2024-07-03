class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int a=0,b=n-1,mid;
        while(a<=b){
            mid=(a+b)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]) a=mid+1;
                else b=mid-1;
            }
            else{
                if(nums[mid]==nums[mid-1]) a=mid+1;
                else b=mid-1;
            }
        }
        return nums[mid];
    }
};
