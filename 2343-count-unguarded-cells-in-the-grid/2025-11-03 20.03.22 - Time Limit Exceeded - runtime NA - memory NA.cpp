class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> maze(m,vector<char>(n,'x'));
        for(int i=0;i<guards.size();i++){
            maze[guards[i][0]][guards[i][1]]='G';
        }
        for(int i=0;i<walls.size();i++){
            maze[walls[i][0]][walls[i][1]]='W';
        }

        for(int i=0;i<guards.size();i++){
            // forward row
            for(int a=guards[i][1];a<n;a++){
                if(maze[guards[i][0]][a]=='W') break;
                else if(maze[guards[i][0]][a]=='G') continue;
                else maze[guards[i][0]][a]='e';
            }

            // backward row
            for(int a=guards[i][1];a>=0;a--){
                if(maze[guards[i][0]][a]=='W') break;
                else if(maze[guards[i][0]][a]=='G') continue;
                else maze[guards[i][0]][a]='e';
            }
            
            // forward col
            for(int a=guards[i][0];a<m;a++){
                if(maze[a][guards[i][1]]=='W') break;
                else if(maze[a][guards[i][1]]=='G') continue;
                else maze[a][guards[i][1]]='e';
            }

            // backward col
            for(int a=guards[i][0];a>=0;a--){
                if(maze[a][guards[i][1]]=='W') break;
                else if(maze[a][guards[i][1]]=='G') continue;
                else maze[a][guards[i][1]]='e';
            }
        }

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(maze[i][j]=='x') ans++;
            }
        }
        return ans;
    }
};
