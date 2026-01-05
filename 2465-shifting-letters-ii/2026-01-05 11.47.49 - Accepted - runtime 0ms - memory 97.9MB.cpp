class Solution {
public:

    string shiftingLetters(string s, vector<vector<int>>& shifts){
        int n=s.length();
        vector<int> val(n,0);
        for(int i=0;i<shifts.size();i++){
            int start=shifts[i][0];
            int end=shifts[i][1];
            int dir=shifts[i][2];

            if(dir==1){
                val[start]+=1;
                if(end+1<n) val[end+1]+=-1;
            }
            else{
                val[start]-=1;
                if(end+1<n) val[end+1]+=1;
            }
        }
        for(int i=1;i<n;i++){
            val[i]+=val[i-1];
        }
        for(int i=0;i<n;i++){
            int x=(s[i]-'a'+val[i])%26;
            if(x<0) x+=26;
            s[i]=(x)+'a';
        }
        return s;
    }
};
