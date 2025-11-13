class Solution {
public:
    int maxOperations(string s) {
        int n=s.length();
        int i=0;
        int cnt_ones=0;
        int ans=0;
        while(i<n){
            if(s[i]=='1'){
                cnt_ones++;
            }
            else{
                while(i+1<n && s[i+1]=='0'){
                    i++;
                }
                ans+=cnt_ones;
            }
            i++;
        }
        return ans;
    }
};
