class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,c=1;
        for(int j=0;j<n;j++){
            if(nums[j]!=nums[i]){
                nums[i+1]=nums[j];
                i++;
                c++;
            }
        }
        return c;
    }
};
