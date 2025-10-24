class Solution {
public:
    bool check(vector<int>& nums, int a,int b){
        for(int i=a+1;i<=b;i++){
            if(nums[i]<=nums[i-1]) return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k<=1) return true;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i+k-1>=n) break;
            if(check(nums,i,i+k-1) && check(nums,i+k,i+2*k-1)) return true;
        }
        return false;
    }
};
