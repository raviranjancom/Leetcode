class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                if(i>0 && nums[i]==nums[i-1]) continue;
                if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k++;
                }
                else{
                    vector<int> t={nums[i],nums[j],nums[k]};
                    ans.push_back(t);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[j-1]) k++;
                }
            }
        }
        return ans;
    }
};
