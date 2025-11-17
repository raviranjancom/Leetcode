class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                int m=i+k;
                i++;
                while(i<=m && i<n){
                    if(nums[i]==1){
                        return false;
                    }
                    i++;
                }
                i--;
            }
        }
        return true;
    }
};
