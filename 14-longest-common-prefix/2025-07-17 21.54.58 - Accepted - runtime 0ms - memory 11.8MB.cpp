class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].length();
        string ans;
        int j=0;
        while(j<m){
            for(int i=1;i<n;i++){
                if(strs[i][j]=='\n' || strs[i-1][j]=='\n'){
                    return ans;
                }
                else if(strs[i-1][j]!=strs[i][j]){
                    return ans;
                }
            }
            if(strs[0]!="") ans.push_back(strs[0][j]);
            j++;
        }
        return ans;
    }
};
