class Solution {
public:
    int minimumLength(string s){
        int n=s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(mp[s[i]]==3){
                mp[s[i]]=1;
            }
        }
        int ans=0;
        for(auto &it:mp){
            ans+=it.second;
        }
        return ans;
    }
};
