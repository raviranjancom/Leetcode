class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length();
        if(n<3) return s;
        string ans;
        for(int i=2;i<n;i++){
            if(s[i-2]==s[i-1]&& s[i-1]==s[i]){
                continue;
            }
            else{
                ans.push_back(s[i-2]);
            }
        }
        ans.push_back(s[n-2]);
        ans.push_back(s[n-1]);
        return ans;
    }
};