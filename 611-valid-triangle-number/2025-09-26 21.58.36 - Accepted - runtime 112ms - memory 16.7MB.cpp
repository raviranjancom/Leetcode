class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++){
            if(nums[i]==0) continue;
            for(int j=i+2;j<n;j++){
                int l=i,r=j;
                int target=nums[j]-nums[i],p=l;
                while(l<=r){
                    int m=(r+l)/2;
                    if(nums[m]<=target){
                        p=m;
                        l=m+1;
                    }
                    else{
                        r=m-1;
                    }
                }
                ans+=j-p-1;
            }
        }
        return ans;
    }
};
