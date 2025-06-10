class Solution {
public:
    int minf(int a, int b, int c){
        if(a>b && a>c) return a;
        else if(b>a && b>c) return b;
        else return c;
    }
    int numberOfSubstrings(string s) {
        int n=s.length();
        int hash[3]={-1, -1, -1};
        int ans=0;
        for(int i=0;i<n;i++){
            hash[s[i] - 'a']=i;
            if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
                int x=minf(hash[0],hash[1],hash[2]);
                ans=ans+x-1;
            }
        }
        return ans;
    }
};