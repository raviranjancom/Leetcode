class Solution {
public:
    int prefixConnected(vector<string>& words, int k){
        unordered_map<string,int> mp;
        int n=words.size();
        for(int i=0;i<n;i++){
            if(words[i].size()>=k){
                auto str=words[i].substr(0,k);
                mp[str]++;
            }
        }
        int ans=0;
        for(auto &it:mp){
            if(it.second>1) ans++;
        }
        return ans;
    }
};
