class Solution {
public:
    bool fun(string &s,int count,int i,int n){
        if(i>=n){
            return (count==0)?true:false;
        }
        if(count<0){
            return false;
        }
        if(s[i]=='('){
            return fun(s,count+1,i+1,n);
        }
        else if(s[i]==')'){
            return fun(s,count-1,i+1,n);
        }
        s[i]='(';
        bool x=fun(s,count+1,i+1,n);
        s[i]='*';
        s[i]=')';
        bool y=fun(s,count-1,i+1,n);
        s[i]='*';
        s[i]=' ';
        bool z=fun(s,count,i+1,n);
        s[i]='*';
        return (x||y||z);
    }
    bool checkValidString(string s) {
        int n=s.length();
        return fun(s,0,0,n);
    }
};