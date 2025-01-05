class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int m=s.size();
        vector<int> zeros(m,0);
        int n=shifts.size();
        for(int i=0;i<n;i++){
            if(shifts[i][2]==1){
                zeros[shifts[i][0]]+=1;
                if(shifts[i][1]+1 < s.size()) zeros[shifts[i][1]+1]-=1;
            }
            else{
                zeros[shifts[i][0]]-=1;
                if(shifts[i][1]+1 < s.size()) zeros[shifts[i][1]+1]+=1;
            }
        }
        vector<int> letters;
        int e=0;
        for(int i=0;i<m;i++){
            letters.push_back(s[i]-97);
            zeros[i]+=e;
            e=zeros[i];
        }
        for(int i=0;i<m;i++){
            letters[i]=(letters[i]+zeros[i])%26;
            if (letters[i] < 0) letters[i] += 26;
        }
        string ans;
        for(int i=0;i<m;i++){
            ans.push_back((char)(letters[i]+97));
        }
        return ans;
    }
};
