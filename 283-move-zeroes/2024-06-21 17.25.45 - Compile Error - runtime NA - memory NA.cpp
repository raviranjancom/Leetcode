class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int ar[n];
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                ar[j]=nums[i];
                j++;
            }
        }
        for(int i=0;i<=j;i++){
            nums[i]=ar[i];
        }
        for(int i=j1;i<n;i++){
            nums[i]=0;
        }
    }
};