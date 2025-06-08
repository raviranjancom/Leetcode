class Solution {
public:
    int maxf(int hash[],string s){
        int ans=-1;
        for(int i=0;i<26;i++){
            ans=max(hash[i], ans);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        int n=s.length();
        int hash[26]={0};
        int l=0,r=0;
        int fre=0;
        int maxlen=0,len=0;
        while(l<n && r<n){
            hash[s[r] - 'A']++;
            fre=max(fre, hash[s[r] - 'A']);
            while(r-l+1-fre >k){
                hash[s[l] - 'A']--;
                l++;
                fre=maxf(hash,s);
            }
            len=r-l+1;
            r++;
            maxlen=max(maxlen, len);
        }
        return maxlen;
    }
};
