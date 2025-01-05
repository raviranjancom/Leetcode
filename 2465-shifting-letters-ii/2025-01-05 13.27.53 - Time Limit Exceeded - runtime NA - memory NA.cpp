class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=shifts.size();
        for(int i=0;i<n;i++){
            for(int j=shifts[i][0];j<=shifts[i][1];j++){
                if(shifts[i][2]==1){
                    // replace with forward letter
                    s[j]='a'+(s[j]-'a'+1)%26;
                }
                else{
                    // replace with backward letter
                    s[j]='a'+(s[j]-'a'+25)%26;
                }
            }
        }
        return s;
    }
};
