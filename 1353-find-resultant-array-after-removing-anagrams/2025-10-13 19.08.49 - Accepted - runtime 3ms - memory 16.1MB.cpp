class Solution {
public:
    bool check(string a, string b){
        if(a.length()!=b.length()) return false;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return  a==b;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1;i<n;i++){
            if(check(ans.back(),words[i])==false){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};