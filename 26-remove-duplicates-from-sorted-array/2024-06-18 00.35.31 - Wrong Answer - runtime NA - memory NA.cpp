class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> v;
        int j=0;
        if (nums.size()>1){
            for(int i=1;i<=nums.size();i++){
            if (nums[i-1]!=nums[i]){
                v.push_back(nums[i-1]);
                j++;
            }
            }
        }
        else{
            v.push_back(nums[0]);
            
        }
        for (int i=0;i<j;i++){
            nums[i]=v[i];
        }
        return j;
    }
};
