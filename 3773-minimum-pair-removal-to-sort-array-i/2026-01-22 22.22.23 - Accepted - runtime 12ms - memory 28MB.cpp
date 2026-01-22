class Solution {
public:
    bool check(vector<int> &nums){
        vector<int> arr=nums;
        sort(arr.begin(),arr.end());
        return arr!=nums;
    }
    int minimumPairRemoval(vector<int>& nums){
        int ans=0;
        
        while(check(nums)){
            ans++;
            int mini=-1,sum=1e9;
            for(int i=0;i<nums.size()-1;i++){
                if(sum>nums[i]+nums[i+1]){
                    mini=i;
                    sum=nums[i]+nums[i+1];
                }
            }
            nums.erase(nums.begin()+mini);
            nums.erase(nums.begin()+mini);
            nums.insert(nums.begin()+mini,sum);
        }
        return ans;
    }
};
