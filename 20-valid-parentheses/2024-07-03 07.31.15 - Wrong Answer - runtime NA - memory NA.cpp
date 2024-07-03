class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        if((mp['(']==mp[')']) && (mp['[']==mp[']']) && (mp['{']==mp['}'])) return true;
        return false;
    }
};
