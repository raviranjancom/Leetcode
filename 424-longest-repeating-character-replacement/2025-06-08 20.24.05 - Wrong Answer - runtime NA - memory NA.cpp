class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            int hash[26]={0};
            int fre=0;
            for(int j=i;j<n;j++){
                hash[s[j] - 'A']++;
                fre=max(fre,hash[s[j] - 'A']);
                int x=j-fre+1;
                if(x<=k){
                    ans=max(ans,j-i+1);
                }
                else break;
            }
        }
        return ans;
    }
};