class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(s1==s2) return true;
        else if(n!=m) return false;
        else{
            int a=-1,b=-1;
            int i=0;
            while(i<n && a==-1){
                if(s1[i]!=s2[i]){
                    a=b;
                    b=i;
                }
                i++;
            }
            if(s1[a]==s2[b] && s1[b]==s2[a]) return true;
        }
        return false;
    }
};