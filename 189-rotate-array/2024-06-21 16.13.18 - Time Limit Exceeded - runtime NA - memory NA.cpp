class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<k;i++){
            int t=nums[n-1];
            for(int j=1;j<n;j++){
                nums[n-j]=nums[n-j-1];
            }
            nums[0]=t;
        }
    }
};