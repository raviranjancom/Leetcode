class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls){
        vector<vector<char>> mat(m,vector<char>(n,'.'));
        for(int i=0;i<guards.size();i++){
            int x=guards[i][0];
            int y=guards[i][1];
            mat[x][y]='G';
        }
        for(int i=0;i<walls.size();i++){
            int x=walls[i][0];
            int y=walls[i][1];
            mat[x][y]='W';
        }
        // lets take prefix sum stratergy here
        // for rows
        for(int i=0;i<m;i++){
            bool s=(mat[i][0]=='G')?true:false;
            for(int j=1;j<n;j++){
                if(mat[i][j]=='W'){
                    s=false;
                }
                else if(mat[i][j]=='G'){
                    s=true;
                }
                else{
                    if(s==true){
                        mat[i][j]='X';
                    }
                }
            }
            s=(mat[i][n-1]=='G')?true:false;
            for(int j=n-2;j>=0;j--){
                if(mat[i][j]=='W'){
                    s=false;
                }
                else if(mat[i][j]=='G'){
                    s=true;
                }
                else{
                    if(s==true){
                        mat[i][j]='X';
                    }
                }
            }
        }
        // for cols
        for(int j=0;j<n;j++){
            bool s=(mat[0][j]=='G')?true:false;
            for(int i=1;i<m;i++){
                if(mat[i][j]=='W'){
                    s=false;
                }
                else if(mat[i][j]=='G'){
                    s=true;
                }
                else{
                    if(s==true){
                        mat[i][j]='X';
                    }
                }
            }
            s=(mat[m-1][j]=='G')?true:false;
            for(int i=m-2;i>=0;i--){
                if(mat[i][j]=='W'){
                    s=false;
                }
                else if(mat[i][j]=='G'){
                    s=true;
                }
                else{
                    if(s==true){
                        mat[i][j]='X';
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]=='.'){
                    ans++;
                }
            }
        }
        return ans;
    }
};
