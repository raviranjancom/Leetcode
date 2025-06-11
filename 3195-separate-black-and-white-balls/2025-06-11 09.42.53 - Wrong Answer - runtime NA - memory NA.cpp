class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            int sw=0;
            for(int j=i;j<n-i;j++){
                if(s[j]=='1' && s[j+1]=='0'){
                    swap(s[j], s[j+1]);
                    ans++;
                    sw++;
                }
            }
            if(sw==0) break;
        }
        return ans;
    }
};
