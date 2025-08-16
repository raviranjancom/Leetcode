class Solution {
public:
    bool check(int hash[],int k){
        for(int i=0;i<26;i++){
            if(hash[i]!=0 && hash[i]<k) return false;
        }
        return true;
    }
    int longestSubstring(string s, int k) {
        int n=s.length(),ans=0;
        for(int i=0;i<n;i++){
            int hash[26]={0};
            for(int j=i;j<n;j++){
                hash[s[j]-'a']++;
                if(check(hash,k)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};