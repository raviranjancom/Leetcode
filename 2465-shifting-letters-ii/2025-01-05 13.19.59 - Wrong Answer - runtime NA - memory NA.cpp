class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=shifts.size();
        for(int i=0;i<n;i++){
            for(int j=shifts[i][0];j<=shifts[i][1];j++){
                if(shifts[i][2]==1){
                    // replace with forward letter
                    if(s[j]=='a') s[j]='z';
                    else s[j]+=1;
                }
                else{
                    // replace with backward letter
                    if(s[j]=='z') s[j]='a';
                    else s[j]-=1;
                }
                if(s[j]=='`') s[j]='z';
                if(s[j]=='{') s[j]='a';
            }
        }
        return s;
    }
};
