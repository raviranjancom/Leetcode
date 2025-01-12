class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n%2==1) return false;
        int close=0,open=0;
        for(int i=0;i<n;i++){
            if(open<0) return false;
            else if(locked[i]=='0' || s[i]=='(') open++;
            else open--;
        }
        for(int i=n-1;i>=0;i--){
            if(close<0) return false;
            else if(locked[i]=='0' || s[i]==')') close++;
            else close--;
        }
        return true;
    }
};