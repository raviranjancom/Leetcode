class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> ans;
        // by cols
        for(int col=0;col<m;col++){
            int i=0,j=col,count=0;
            while(j>=0 && i<=col && i<n){
                ans.push_back(mat[i][j]);
                i++;
                j--;
                count++;
            }
            if(col%2==0){
                reverse(ans.end()-count,ans.end());
            }
        }

        // by cols
        for(int row=1;row<n;row++){
            int i=row,j=m-1;
            while(i<n && j>=0 && i>=0){
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
            if(row%2==0)reverse(ans.end()-(n-row),ans.end());
        }
        return ans;
    }
};
