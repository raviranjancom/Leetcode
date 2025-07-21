class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,-1));
        int rows=0,cols=0,count=1;
        while(rows<n && cols<n){
            for(int i=cols;i<n-cols;i++){
                ans[rows][i]=count;
                count++;
                if(count>n*n) return ans;
            }
            for(int i=rows+1;i<n-rows;i++){
                ans[i][n-1-cols]=count;
                count++;
                if(count>n*n) return ans;
            }
            for(int i=n-2-cols;i>=cols;i--){
                ans[n-1-rows][i]=count;
                count++;
                if(count>n*n) return ans;
            }
            for(int i=n-2-rows;i>rows;i--){
                ans[i][cols]=count;
                count++;
                if(count>n*n) return ans;
            }
            rows++;
            cols++;
        }
        return ans;
    }
};
