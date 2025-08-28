class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        // for rows
        for(int row=0;row<n-1;row++){
            // sorting along rows
            for(int i=row,j=0;i<n && j<m;i++,j++){
                // int swaped=0;
                for(int x=row,y=0;x<=n-1-i && y<m-1-j;x++,y++){
                    if(grid[x][y] < grid[x+1][y+1]){
                        swap(grid[x][y],grid[x+1][y+1]);
                        // swaped++;
                    }
                    // if(swaped==0) break;
                }
            }
        }

        // for cols
        for(int col=1;col<n-1;col++){
            // sorting along cols
            for(int i=0,j=col;i<n && j<m;i++,j++){
                // int swaped=0;
                for(int x=0,y=col;x<n-1-i && y<=m-1-j;x++,y++){
                    if(grid[x][y] > grid[x+1][y+1]){
                        swap(grid[x][y],grid[x+1][y+1]);
                        // swaped++;
                    }
                    // if(swaped==0) break;
                }
            }
        }
        return grid;
    }
};
