class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,-1));
        int rows=0,cols=0,count=1;
        while(rows<n && cols<n){
            for(int i=0;i<n;i++){
                ans[rows][i]=count;
                count++;
                if(count==n*n+1) return ans;
            }
            for(int i=rows+1;i<n;i++){
                ans[i][n-1-cols]=count;
                count++;
                if(count==n*n+1) return ans;
            }
            for(int i=n-2-cols;i>=cols;i--){
                ans[n-1-rows][i]=count;
                count++;
                if(count==n*n+1) return ans;
            }
            for(int i=rows+1;i<n-2-rows;i++){
                ans[i][cols]=count;
                count++;
                if(count==n*n+1) return ans;
            }
            rows++;
            cols++;
        }
        return ans;
    }
};
