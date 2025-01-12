class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                for(int j=0;j<m;j++){
                    if((i+j)%2==0 && i%2==0) ans.push_back(grid[i][j]);
                }
            }
            if(i%2==1){
                for(int k=m-1;k>-1;k--){
                    if((i+k)%2==0 && i%2==1) ans.push_back(grid[i][k]);
                }
            }
        }
        return ans;
    }
};
