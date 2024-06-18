class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int flag;
        map<int,int> mpp;
        for(int j=0;j<n;j++){
            mpp[nums[j]]++;
        }
        for(int j=0;j<mpp.size();j++){
            if (mpp[j]==1){
                flag=j;
            }
        }
    return flag;
    }
};