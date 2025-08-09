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
    string substr(string s, int i,int j){
        string ans;
        for(int k=i;k<=j;k++){
            ans+=s[k];
        }
        return ans;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        string ans;
        int maxlen=0;
        int a=0,b=0;
        vector<vector<string>> dp(n, vector<string>(n, "#"));
        for(int i=0;i<n;i++){
            for(int j=i+maxlen;j<n;j++){
                if(is_palindrome(s,i,j,dp)){
                    if(maxlen<j-i+1){
                        maxlen=j-i+1;
                        a=i;
                        b=j;
                    }
                }
            }
        }
        
        return substr(s,a,b);
    }
};
