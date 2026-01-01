class Solution {
public:
    int maxScore(string s) {
        int right_ones=0;
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='1') right_ones++;
        }
        int left_zeros=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                left_zeros++;
            }
            else{
                right_ones--;
            }
            ans=max(ans,left_zeros+right_ones);
        }
        return ans;
    }
};
