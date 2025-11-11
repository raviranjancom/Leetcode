class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        int ans=0;
        for(int element : st){
            if(element==0) continue;
            bool flag=true;
            int ds=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==element){
                    if(flag==true){
                        ds++;
                        flag=false;
                    }
                }
                else if(nums[i]<element){
                    flag=true;
                }
            }
            ans+=ds;
        }
        return ans;
    }
};
