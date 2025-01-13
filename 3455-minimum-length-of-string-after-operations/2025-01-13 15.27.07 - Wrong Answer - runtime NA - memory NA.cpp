class Solution {
public:
    int minimumLength(string s) {
        int n=s.length(),ans=0;
        map<int, int> count;
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            int x=count[i]/3;
            ans+=x;
        }
        return n-2*ans;
    }
};
