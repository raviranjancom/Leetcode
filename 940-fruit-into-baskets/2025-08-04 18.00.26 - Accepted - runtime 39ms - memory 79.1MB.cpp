class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int left=0,right=0;
        map<int,int> mp;
        int ans=0;
        while(left<n && right<n){
            mp[fruits[right]]++;
            while(mp.size()>2 && left<n){
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            ans=max(right-left+1,ans);
            right++;
        }
        return ans;
    }
};
