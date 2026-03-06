class Solution {
public:
    bool checkOnesSegment(string s){
        int n=s.length();
        int ans=1;
        for(int i=0;i<n;i++){
            if(i>0 && s[i]=='1' && s[i-1]=='0'){
                ans++;
            }
            if(ans>1) return false;
        }
        return true;
    }
};
