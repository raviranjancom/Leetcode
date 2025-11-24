class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool> ans;
        int carry=0;
        for(int i=0;i<n;i++){
            int unitDigit=nums[i];
            carry=carry<<1;
            carry=(carry+unitDigit)%5;
            if(carry==0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};
