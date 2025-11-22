class Solution {
public:
    int countPalindromicSubsequence(string s){
        int n=s.length();
        int ans=0;
        unordered_map<char,int> mp;  // key => index
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
            }
            else{
                int oldKey=mp[s[i]];
                if(oldKey+1==i){
                    continue;
                }
                else{
                    ans+=(i-oldKey-1);
                    mp[s[i]]=i;
                }
            }
        }
        return ans;
    }
};
