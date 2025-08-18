class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int min=0,max=0;
        for(int i=0;i<n;i++){
            if(max<0) return false;
            if(s[i]=='('){
                min++;
                max++;
            }
            else if(s[i]=='*'){
                max++;
                if(min>0) min--;
            }
            else{
                if(min>0) min--;
                max--;
            }
        }
        if(min==0) return true;
        return false;
    }
};
