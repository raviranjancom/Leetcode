class Solution {
public:
    int solve(vector<string> &strs,vector<vector<int>> &mp,int m, int n, int idx){
        if(m<0 || n<0 || idx>=strs.size()){
            return 0;
        }
        //take
        int x=1+solve(strs,mp,m-mp[idx][0],n-mp[idx][1],idx+1);
        // not take
        int y=solve(strs,mp,m,n,idx+1);

        return max(x,y);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> mp(strs.size(),vector<int>(2,0));
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].length();j++){
                if(strs[i][j]=='0'){
                    mp[i][0]++;
                }
                else{
                    mp[i][1]++;
                }
            }
        }
        return solve(strs,mp,m,n,0);
    }
};