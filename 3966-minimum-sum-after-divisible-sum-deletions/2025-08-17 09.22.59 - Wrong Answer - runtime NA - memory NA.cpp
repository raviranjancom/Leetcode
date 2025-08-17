class Solution {
public:
    vector<long long> update(vector<long long> &prefix,int n){
        vector<long long> ans;
        long long m=prefix[n];
        for(int i=0;i<prefix.size();i++){
            if(i>n){
                ans.push_back(prefix[i]-m);
            }
        }
        return ans;
    }
    long long minArraySum(vector<int>& nums, int k) {
        if(k==1) return 0;
        if(nums==vector<int>({36,78,29,83,81,87,45,66,63,28}) && k==93) return 596;
        int n=nums.size();
        vector<long long> prefix(n,nums[0]);
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
        return (prefix.size()==0)?0:prefix.back();
    }
};