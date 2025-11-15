class Solution {
public:
    unordered_map<int,vector<char>> mp={
        {'2',{'a','b','c'}},
        {'3',{'d','e','f'}},
        {'4',{'g','h','i'}},
        {'5',{'j','k','l'}},
        {'6',{'m','n','o'}},
        {'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},
        {'9',{'w','x','y','z'}}
    };
    void solve(string &digits,vector<string> &ans, string &ds,int idx){
        if(idx==digits.size()){
            ans.push_back(ds);
            return ;
        }
        for(auto ch:mp[digits[idx]]){
            ds.push_back(ch);
            solve(digits,ans,ds,idx+1);
            ds.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits){
        vector<string> ans;
        string ds;
        solve(digits,ans,ds,0);
        return ans;
    }
};
