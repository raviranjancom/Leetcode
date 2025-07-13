class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.length();
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]>=97 && s[i]<=122){
                ans.push_back(s[i]);
            }
            else if(s[i]=='*'){
                if(ans.length()>0){
                    ans.pop_back();
                }
                else{
                    continue;
                }
            }
            else if(s[i]=='#'){
                ans=ans+ans;
            }
            else if(s[i]=='%'){
                reverse(ans.begin(),ans.end());
            }
        }
        if(k<ans.length()) return ans[k];
        return '.';
    }
};