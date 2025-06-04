class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int zeros=k;
        int l=0,r=0;
        int len=0,maxlen=0;
        while(l<n && r<n){
            if(nums[r]==0){
                zeros--;
            }
            while(zeros<0){
                if(nums[l]==0) zeros++;
                l++;
            }
            r++;
            len=r-l;
            maxlen=max(len,maxlen);
        }
        return maxlen;
    }
};
