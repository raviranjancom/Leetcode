class Solution {
public:
    bool check(unordered_map<char,int> &mp,int x){
        for(auto &it:mp){
            if(x!=it.second) return false;
        }
        return true;
    }
    int longestBalanced(string s){
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(check(mp,mp[s[i]])){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
