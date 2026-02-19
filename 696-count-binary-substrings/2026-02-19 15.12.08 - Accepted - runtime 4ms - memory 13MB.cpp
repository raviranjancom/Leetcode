class Solution {
public:
    int countBinarySubstrings(string s){
        int n=s.length();
        int zeros=0,ones=0;
        if(s[0]=='0') zeros++;
        if(s[0]=='1') ones++;
        int ans=0;
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                if(s[i-1]=='0'){
                    ans+=min(zeros,ones);
                    ones=1;
                }
                else{
                    ones++;
                }
            }
            else{
                if(s[i-1]=='1'){
                    ans+=min(zeros,ones);
                    zeros=1;
                }
                else{
                    zeros++;
                }
            }
        }
        ans+=min(zeros,ones);
        return ans;
    }
};
