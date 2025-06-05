class Solution {
public:
    void subset(vector<int> nums, vector<int> &ans,int target){
        vector<int> temp;
        int n=nums.size();
        n=pow(2,n);
        for(int i=0;i<n;i++){
            int p=1;
            for(int j=0;j<32;j++){
                if((i&(1<<j))!=0){
                    p=p*nums[j];
                }
            }
            if(p==target) ans.push_back(p);
        }
        return ;
    }
    
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        vector<int> ans;
        subset(nums, ans,target);
        int n=ans.size();
        if(target==1){
            bool result = (n>2) ? true : false;
            return result;
        }
        bool result = (n>1) ? true : false;
        return result;
    }
};
