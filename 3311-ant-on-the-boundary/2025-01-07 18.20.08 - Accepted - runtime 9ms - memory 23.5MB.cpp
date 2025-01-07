class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ans=0,move=0;
        for(int i=0;i<nums.size();i++){
            move+=nums[i];
            if(move==0) ans++;
        }
        return ans;
    }
};