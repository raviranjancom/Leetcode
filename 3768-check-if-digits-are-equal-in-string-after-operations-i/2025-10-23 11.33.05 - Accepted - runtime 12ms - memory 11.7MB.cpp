class Solution {
public:
    int calculate(char a, char b){
        int x=a-'0';
        int y=b-'0';
        return (x+y)%10;
    }
    bool hasSameDigits(string s) {
        int n=s.length();
        for(int i=0;i<n-2;i++){
            string x;
            for(int i=0;i<n-1;i++){
                x.push_back(calculate(s[i],s[i+1]));
            }
            s=x;
        }
        if(s[0]==s[1]) return true;
        return false;
    }
};
