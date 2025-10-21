class Solution {
public:
    int lower_bound(vector<int>& nums,int l,int r, int t){
        while(l>=0 && r<nums.size() && l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>=t){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
    int upper_bound(vector<int>& nums,int l,int r, int t){
        while(l>=0 && r<nums.size() && l<r){
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
        int n=nums.size(),ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int lb=nums[i]-k;
            int ub=nums[i]+k;

            int x=lower_bound(nums,0,i,lb);
            int y=upper_bound(nums,i,n-1,ub);
            ans=max(ans,abs(y-x+1));
        }
        return ans;
    }
};
