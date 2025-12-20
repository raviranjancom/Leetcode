class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].length();
        int ans=0;
        for(int j=0;j<m;j++){
            string s;
            for(int i=0;i<n;i++){
                s+=strs[i][j];
            }
            string r=s;
            sort(s.begin(),s.end());
            if(s!=r) ans++;
        }
        return ans;
    }
};
