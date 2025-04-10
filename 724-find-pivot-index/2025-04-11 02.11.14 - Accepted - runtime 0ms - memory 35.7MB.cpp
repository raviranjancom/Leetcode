class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int rightSum=0,leftSum=0;
        for(int i=0;i<n;i++){
            rightSum+=nums[i];
        }

        int previous=0;
        for(int i=0;i<n;i++){
            leftSum+=previous;
            rightSum-=nums[i];
            previous=nums[i];
            if(leftSum==rightSum){
                return i;
            }
        }
        return -1;
    }
};
