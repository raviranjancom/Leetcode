class Solution {
public:
    void rotate(vector<int>& nums, int k){
        int n=nums.size();
        k=k%n;
        int x=n-k;
        vector<int> v1(nums.begin()+x,nums.end());
        vector<int> v2(nums.begin(),nums.begin()+x);

        for(int i=0;i<v1.size();i++){
            nums[i]=v1[i];
        }
        for(int i=0;i<v2.size();i++){
            nums[i+v1.size()]=v2[i];
        }
    }
};
