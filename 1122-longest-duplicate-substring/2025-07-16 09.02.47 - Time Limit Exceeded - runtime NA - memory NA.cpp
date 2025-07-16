class Solution {
public:
    string longestDupSubstring(string s) {
        unordered_map<string, int> mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            string x;
            for(int j=i;j<n;j++){
                x+=s[j];
                mp[x]++;
            }
        }
        int ans=0;
        string res="";
        for(auto it:mp){
            if(it.second>1 && it.first.length()>ans){
                ans=it.first.length();
                res=it.first;
            }
        }
        return res;
    }
};