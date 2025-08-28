class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        // for rows
        for(int row=0;row<n-1;row++){
            // sorting along rows
            for(int p=0;p<n;p++){
                for(int x=row,y=0;x<n-1 && y<m-1;x++,y++){
                    if(grid[x][y] < grid[x+1][y+1]){
                        swap(grid[x][y],grid[x+1][y+1]);
                    }
                }
            }
        }

        // for cols
        for(int col=1;col<m-1;col++){
            // sorting along cols
            for(int p=0;p<n;p++){
                for(int x=0,y=col;x<n-1 && y<m-1;x++,y++){
                    if(grid[x][y] > grid[x+1][y+1]){
                        swap(grid[x][y],grid[x+1][y+1]);
                    }
                }
            }
        }
        return grid;
    }
};
