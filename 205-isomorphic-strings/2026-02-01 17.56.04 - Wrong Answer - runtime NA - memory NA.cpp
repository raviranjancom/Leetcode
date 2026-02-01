class Solution {
public:
    bool isIsomorphic(string s, string t){
        if(s.length() != t.length()) return false;
        unordered_map<int,int> mp;
        int n=s.length();
        for(int i=0,j=0;i<n&&j<n;i++,j++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]]!=t[j]){
                return false;
            }
            else{
                mp[s[i]]=t[j];
            }
        }
        return true;
    }
};
