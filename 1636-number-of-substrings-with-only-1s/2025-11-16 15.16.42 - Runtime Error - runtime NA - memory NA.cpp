class Solution {
public:
    int numSub(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            while(s[i]=='1'){
                cnt++;
                i++;
            }
            ans+=(cnt)*(cnt+1)/2;
        }
        return ans;
    }
};
