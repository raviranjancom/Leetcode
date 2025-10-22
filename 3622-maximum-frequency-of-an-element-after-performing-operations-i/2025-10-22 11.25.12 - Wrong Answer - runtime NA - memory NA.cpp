class Solution {
public:
    int lower_bound(vector<int>& nums,int l,int r, int t){
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]<t){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
    }
    int upper_bound(vector<int>& nums,int l,int r, int t){
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]<=t){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
    }
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size(),ans=1;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }

        for(int i=0;i<100001;i++){
            int lb=(i-k>0)?i-k:0;
            int ub=(i+k<100001)?i+k:0;

            int x=lower_bound(nums,0,n,lb);
            int y=upper_bound(nums,0,n,ub);
            ans=max(ans,min(abs(y-x)-mp[i],numOperations)+mp[i]);
        }
        return ans;
    }
};
