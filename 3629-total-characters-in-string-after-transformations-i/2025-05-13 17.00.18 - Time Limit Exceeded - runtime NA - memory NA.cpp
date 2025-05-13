class Solution {
public:
    string transform(string s, int n){
        string x="";
        for(int i=0;i<n;i++){
            if(s[i]=='z'){
                x.push_back('a');
                x.push_back('b');
            }
            else{
                x.push_back(s[i]+1);
            }
        }
        return x;
    }
    int lengthAfterTransformations(string s, int t) {
        for(int i=0;i<t;i++){
            long long n=s.length();
            s=transform(s,n);
        }
        long long n=s.length();
        return n;
    }
};