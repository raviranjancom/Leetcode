class Solution {
public:
    bool is_palindrome(string s,int low ,int high,vector<vector<int>> &dp){
        if(low>=high){
            return dp[low][high] = 1;
        }
        if(dp[low][high]==1) return 1;
        if(s[low]==s[high]){
            return dp[low][high] = is_palindrome(s,low+1,high-1,dp);
        }
        else{
            return dp[low][high]=0;
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
        int start=0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(is_palindrome(s,i,j,dp)){
                    if(maxlen<j-i+1){
                        maxlen=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return substr(s,start,start+maxlen-1);
    }
};
