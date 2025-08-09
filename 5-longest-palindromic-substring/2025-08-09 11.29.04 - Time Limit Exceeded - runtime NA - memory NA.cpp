class Solution {
public:
bool is_palindrome(string s,int low ,int high,vector<vector<string>> &dp){
    if(low>=high){
        dp[low][high]=s;
        return true;
    }
    if(dp[low][high]!="#") return true;
    if(s[low]==s[high]){
        return is_palindrome(s,low+1,high-1,dp);
    }
    else{
        return false;
    }
}
    string longestPalindrome(string s) {
        int n=s.length();
        set<string> ds;
        vector<vector<string>> dp(n, vector<string>(n, "#"));
        for(int i=0;i<n;i++){
            string x;
            for(int j=i;j<n;j++){
                x+=s[j];
                if(is_palindrome(x,0,x.length()-1,dp)) ds.insert(x);
            }
        }
        string ans;
        int maxlen=0;
        for(string it:ds){
            if(maxlen<it.length()){
                maxlen=it.length();
                ans=it;
            }
        }
        return ans;
    }
};
