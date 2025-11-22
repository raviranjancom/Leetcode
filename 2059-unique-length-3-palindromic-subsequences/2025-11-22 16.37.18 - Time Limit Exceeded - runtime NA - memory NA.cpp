class Solution {
public:
    bool is_palindrome(string &s){
        if(s[0]==s[2]) return true;
        return false;
    }
    void solve(string &s,int idx,set<string> &ans,string &ds,int cnt){
        if(cnt==0){
            if(is_palindrome(ds)) ans.insert(ds);
            return ;
        }
        else if(idx>=s.size()){
            return ;
        }
        // take
        ds.push_back(s[idx]);
        solve(s,idx+1,ans,ds,cnt-1);
        ds.pop_back();
        // Not Take
        solve(s,idx+1,ans,ds,cnt);
    }
    int countPalindromicSubsequence(string s){
        int n=s.size();
        set<string> ans;
        string ds;
        for(int i=0;i<n;i++){
            solve(s,i,ans,ds,3);
        }
        return ans.size();
    }
};
