class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxfre=1,ans=1,fre=1;
        sort(nums.begin(),nums.end());

        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                fre++;
            }
            else{
                if(maxfre<fre){
                    maxfre=fre;
                    ans=maxfre;
                }
                else if(maxfre==fre){
                    ans+=maxfre;
                }
                fre=1;
            }
        }
        return ans;
    }
};
