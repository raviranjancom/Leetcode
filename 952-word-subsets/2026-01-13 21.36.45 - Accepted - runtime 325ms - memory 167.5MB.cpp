class Solution {
public:
    bool solve(string &s,unordered_map<char,int> &mp){
        unordered_map<char,int> ds;
        for(char &it:s){
            ds[it]++;
        }
        for(auto &it:mp){
            if(it.second>ds[it.first]) return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2){
        int n=words1.size(),m=words2.size();
        unordered_map<char,int> mp;
        vector<string> ans;
        for(string &it:words2){
            unordered_map<char,int> ds;
            for(char &jt:it){
                ds[jt]++;
                mp[jt]=max(mp[jt],ds[jt]);
            }
        }
        for(auto it:words1){
            if(solve(it,mp)==true){
                ans.push_back(it);
            }
        }
        return ans;
    }
};
