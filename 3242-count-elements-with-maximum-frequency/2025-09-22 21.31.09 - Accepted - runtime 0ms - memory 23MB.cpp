#include<cstdint>
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int8_t hash[101]={0},m=-1,ans=0;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
            m=max(m,hash[nums[i]]);
        }

        for(int i=0;i<=100;i++){
            if(hash[i]==m) ans+=hash[i];
        }
        return ans;
    }
};