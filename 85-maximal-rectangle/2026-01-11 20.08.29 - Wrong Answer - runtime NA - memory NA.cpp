class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> matH(n,vector<int>(m,0)),matV(n,vector<int>(m,0));
        // matH
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    matH[i][j]=(matrix[i][j]=='0')?0:1;
                }
                else{
                    matH[i][j]=(matrix[i][j]=='0')?0:matH[i-1][j]+1;
                }
            }
        }
        // matV
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(j==0){
                    matV[i][j]=(matrix[i][j]=='0')?0:1;
                }
                else{
                    matV[i][j]=(matrix[i][j]=='0')?0:matV[i][j-1]+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x=matH[i][j],y=1e9;
                for(int k=i;k>i-x;k--){
                    y=min(y,matV[k][j]);
                }
                ans=max(ans,y*x);
            }
        }
        return ans;
    }
};
