class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,maxscore=0,score=0;
        unordered_map<int,int> mp;
        while(l<n && r<n){
            mp[nums[r]]++;
            score+=nums[r];
            while(mp[nums[r]]==2 && r<n && l<n){
                score-=nums[l];
                mp[nums[l]]--;
                l++;
            }
            maxscore=max(maxscore,score);
            cout<<r-l+1<<" ";
            r++;
        }
        return maxscore;
    }
};