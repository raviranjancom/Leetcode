class Solution {
public:
    bool  solve(unordered_map<char,int> mp,string &str){
        for(auto it:str){
            if(mp.find(it)==mp.end()) return false;
            else{
                mp[it]--;
                if(mp[it]==0) mp.erase(it);
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2){
        vector<string> ans;
        for(auto it:words1){
            bool flag=true;
            unordered_map<char,int> mp;
            for(auto &kt:it){
                mp[kt]++;
            }
            for(auto jt:words2){
                if(solve(mp,jt)==false){
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(it);
        }
        return ans;
    }
};