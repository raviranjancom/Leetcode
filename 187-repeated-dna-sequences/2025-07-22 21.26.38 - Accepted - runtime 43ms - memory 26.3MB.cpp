class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        int n=s.length(),l=0,r=0;
        string str;
        while(l<n && r<n){
            str+=s[r];
            if(r-l+1<10){
                r++;
            }
            else{
                mp[str]++;
                str.erase(0,1);
                l++;
                r++;
            }
        }
        vector<string> ans;
        for(auto it:mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
