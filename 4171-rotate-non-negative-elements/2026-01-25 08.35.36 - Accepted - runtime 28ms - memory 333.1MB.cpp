class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k){
        if(k==0) return nums;
        vector<int> ds;
        for(auto &it:nums){
            if(it>=0) ds.push_back(it);
        }
        int n=ds.size();
        if(n==0) return nums;
        k=k%n;
        vector<int> p1,p2;
        for(int i=0;i<k;i++){
            p1.push_back(ds[i]);
        }
        for(int i=k;i<n;i++){
            p2.push_back(ds[i]);
        }
        vector<int> ds2;
        for(int i=0;i<p2.size();i++){
            ds2.push_back(p2[i]);
        }
        for(int i=0;i<p1.size();i++){
            ds2.push_back(p1[i]);
        }
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                nums[i]=ds2[j];
                j++;
            }
        }
        return nums;
    }
};
