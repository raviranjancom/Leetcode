class Solution {
public:
    vector<int> update(vector<int> &prefix,int n){
        vector<int> ans;
        int m=prefix[n];
        for(int i=0;i<prefix.size();i++){
            if(i<=n){
                continue;
            }
            else{
                ans.push_back(prefix[i]-m);
            }
        }
        return ans;
    }
    long long minArraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n,nums[0]);
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        int i=0;
        while(i<n){
            if(prefix[i]%k==0){
                prefix=update(prefix,i);
                n=prefix.size();
                i=0;
            }
            i++;
        }
        return prefix.back();
    }
};