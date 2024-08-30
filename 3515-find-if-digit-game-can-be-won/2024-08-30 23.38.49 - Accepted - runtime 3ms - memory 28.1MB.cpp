class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int alice=0,bob=0;
        int n=size(nums);
        for(int i=0;i<n;i++){
            if(nums[i]<10) alice+=nums[i];
            else bob+=nums[i];
        }
        if(alice!=bob) return true;
        else return false;
    }
};