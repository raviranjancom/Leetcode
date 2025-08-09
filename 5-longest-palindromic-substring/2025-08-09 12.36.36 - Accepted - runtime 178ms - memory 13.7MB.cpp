class Solution {
public:
    int dp[1001][1001];
    bool is_palindrome(string &s,int low ,int high){
        if(low>=high){
            return dp[low][high] = 1;
        }
        if(dp[low][high]!=-1) return dp[low][high];
        if(s[low]==s[high]){
            return dp[low][high] = is_palindrome(s,low+1,high-1);
        }
        else{
            return dp[low][high]=0;
        }
    }
    
    string longestPalindrome(string s) {
        int n=s.length();
        string ans;
        int maxlen=0;
        int start=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(is_palindrome(s,i,j)){
                    if(maxlen<j-i+1){
                        maxlen=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};
