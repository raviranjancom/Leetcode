void fun(vector<vector<int>> &matrix, int n, int m, int r, int c){
    for(int a=0;a<n;a++){
        if(matrix[r][a]==0) continue;
        matrix[r][a]=-11;
    }
    for(int a=0;a<m;a++){
        if(matrix[r][a]==0) continue;
        matrix[a][c]=-11;
    }
}
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) fun(matrix, n, m, i, j);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==-11) matrix[i][j]=0;
            }
        }
    }
};