class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        int row=0,col=0;
        int count=0;
        while(count<n*m){
            for(int i=col;i<m-col;i++){
                if(count>=n*m) return ans;
                ans.push_back(matrix[row][i]);
                count++;
            }
            for(int i=row+1;i<n-row;i++){
                if(count>=n*m) return ans;
                ans.push_back(matrix[i][m-1-col]);
                count++;
            }
            for(int i=m-2-col;i>=col;i--){
                if(count>=n*m) return ans;
                ans.push_back(matrix[n-1-row][i]);
                count++;
            }
            for(int i=n-2-row;i>=row+1;i--){
                if(count>=n*m) return ans;
                ans.push_back(matrix[i][col]);
                count++;
            }
            row++;
            col++;
        }
        return ans;
    }
};