class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int> mp;
        int l=0,r=0;
        int len=0,result=0;
        while(l<n && r<n){
            mp[s[r]]++;
            while(mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
                len--;
            }

            r++;
            len++;
            result=max(len,result);
        }
        return result;
    }
};
