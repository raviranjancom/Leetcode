class Solution {
public:
    bool checkRecord(string s) {
        int n=s.length();
        bool rule1=false, rule2=false;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='A'){
                count++;
            }
            if(count==2){
                rule1=true;
                break;
            }
        }

        for(int i=0;i<n-2;i++){
            if(s[i]=='L' && s[i+1]=='L' && s[i+2]=='L'){
                rule2=true;
                break;
            }
        }
        if(rule1 || rule2){
            return false;
        }
        return true;
    }
};