class Solution {
public:
    void divide(string &s){
        s.pop_back();
    }
    string add(string s){
        int n=s.length();
        int carry=1;
        bool flag=true;
        for(int i=n-1;i>=0 && carry==1;i--){
            if(s[i]=='1'){
                s[i]='0';
            }
            else{
                s[i]='1';
                carry=0;
                flag=false;
            }
        }
        if(flag) return "1"+s;
        return s;
    }
    int numSteps(string s){
        int n=s.length();
        int ans=0;
        while(s!="1"){
            if(s.back()=='1'){
                s=add(s);
            }
            else{
                divide(s);
            }
            ans++;
        }
        return ans;
    }
};
