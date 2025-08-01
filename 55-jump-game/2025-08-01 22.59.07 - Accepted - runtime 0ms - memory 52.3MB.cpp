class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            if(maxlen<i){
                return false;
            }
            maxlen=max(nums[i]+i,maxlen);
        }
        return true;
    }
};
