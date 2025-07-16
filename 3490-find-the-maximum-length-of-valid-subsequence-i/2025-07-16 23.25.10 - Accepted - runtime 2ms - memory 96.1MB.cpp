class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int oddCount=0,evenCount=0;
        int alternating=0;
        for(auto it:nums){
            if(it%2==1) oddCount++;
            else evenCount++;
        }
        int prev=nums[0]%2;
        int ans=1;
        for(int i=1;i<n;i++){
            int parity=nums[i]%2;
            if(parity!=prev){
                ans++;
                prev=parity;
            }
        }
        return max(ans,max(evenCount,oddCount));
    }
};
