class Solution {
public:
    int minLength(vector<int>& nums, int k){
        int ans=1e9;
        int n=nums.size();
        int i=0,j=0;
        int sum=0;
        unordered_map<int,int> mp;
        while(i<n && j<=n){
            if(sum<k){
                int size=mp.size();
                if(j<n) mp[nums[j]]++;
                if(size<mp.size() && j<n){
                    sum+=nums[j];
                }
                j++;
            }
            else{
                ans=min(ans,j-i);
                mp[nums[i]]--;
                int size=mp.size();
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                if(size>mp.size()){
                    sum-=nums[i];
                }
                i++;
            }
        }
        return (ans==1e9)?-1:ans;
    }
};
