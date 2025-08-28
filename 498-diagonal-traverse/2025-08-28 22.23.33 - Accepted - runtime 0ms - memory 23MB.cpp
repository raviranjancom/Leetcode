class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),flip=1;
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
            if(flip==1){
                reverse(ans.end()-count,ans.end());
                flip=0;
            }
            else flip=1;
        }

        // by cols
        for(int row=1;row<n;row++){
            int i=row,j=m-1,count=0;
            while(i<n && j>=0 && i>=0){
                ans.push_back(mat[i][j]);
                i++;
                j--;
                count++;
            }
            if(flip==1){
                reverse(ans.end()-count,ans.end());
                flip=0;
            }
            else flip=1;
        }
        return ans;
    }
};
