class Solution {
public:
    bool check(string a, string b){
        if(a.length()!=b.length()) return false;
        unordered_map<char,int> st1,st2;
        for(int i=0;i<a.length();i++){
            st1[a[i]]++;
            st2[b[i]]++;
        }
        return st1==st2;
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