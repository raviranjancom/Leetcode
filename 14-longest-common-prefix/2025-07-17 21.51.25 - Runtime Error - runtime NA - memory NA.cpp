class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans;
        int j=0;
        while(j>-1){
            for(int i=1;i<n;i++){
                if(strs[i][j]=='\n' || strs[i-1][j]=='\n'){
                    return ans;
                }
                else if(strs[i-1][j]!=strs[i][j]){
                    return ans;
                }
            }
            ans.push_back(strs[0][j]);
            j++;
        }
        return ans;
    }
};
