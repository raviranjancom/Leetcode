class Solution {
public:
    int minimumDeletions(string s){
        int n=s.length();
        int countA=0,countB=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a') countA++;
            if(s[i]=='b') countB++;
        }
        int x=0,y=0,ans=1e9;
        for(int i=0;i<n;i++){
            if(s[i]=='a') x++;
            if(s[i]=='b') y++;
            ans=min(ans,y+countA-x);
        }
        return ans;
    }
};
