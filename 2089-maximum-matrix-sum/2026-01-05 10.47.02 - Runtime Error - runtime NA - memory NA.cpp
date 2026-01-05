class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int total=0,minN=1e9,cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total+=abs(matrix[i][j]);
                if(matrix[i][j]<0) cnt++;
                minN=min(minN,abs(matrix[i][j]));
            }
        }
        if(cnt%2==0){
            return total;
        }
        return total-2*minN;
    }
};
