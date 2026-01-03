class Solution {
public:
    int waysToSplitArray(vector<int>& arr){
        vector<long long> nums;
        for(int i=0;i<arr.size();i++){
            nums.push_back(arr[i]);
        }
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            long long left=nums[i];
            long long right=nums[n-1]-nums[i];
            if(left>=right){
                ans++;
            }
        }
        return ans;
    }
};
