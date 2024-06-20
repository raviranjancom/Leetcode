class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int m=0;
    int c=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            c++;
            if(m<c){
                m=c;
            }
        }
        else{
            c=0;
        }
    }
    return m;
    }
};