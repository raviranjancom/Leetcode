class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mp;
        int a,b;
        for(int i=0;i<n;i++){
            if(mp[target-nums[i]]>0){
                a=target-nums[i];
                b=i;
            }
            else mp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==a){
                a=i;
                break;
            }
        }
        return {a,b};
    }
};