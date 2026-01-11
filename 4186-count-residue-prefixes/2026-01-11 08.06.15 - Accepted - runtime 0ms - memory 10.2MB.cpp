class Solution {
public:
    int residuePrefixes(string s){
        int n=s.length();
        unordered_map<char,int> mp;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(mp.size()==(i+1)%3){
                ans++;
            }
        }
        return ans;
    }
};
