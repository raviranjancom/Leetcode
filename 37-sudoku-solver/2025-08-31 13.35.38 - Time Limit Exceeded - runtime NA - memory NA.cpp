class Solution {
public :
    bool solve(vector<vector<char>>& board,int cr,int cc){
        int val=board[cr][cc];
        // check row
        for(int col=0;col<9;col++){
            if(col == cc || board[cr][col]=='.') continue;
            else if(board[cr][col]==val) return false;
        }
        
        // check col
        for(int row=0;row<9;row++){
            if(row == cr || board[row][cc]=='.') continue;
            else if(board[row][cc]==val) return false;
        }
        // check grid
        int start_row=3*(cr/3);
        int end_row=3*((cr/3)+1);
        end_row-=1;
        int start_col=3*(cc/3);
        int end_col=3*((cc/3)+1);
        end_col-=1;
        
        for(int i=start_row;i<=end_row;i++){
            for(int j=start_col;j<=end_col;j++){
                if((cr==i && cc==j) || board[i][j]=='.') continue;
                else if(board[i][j]==val) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        bool ans=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(board[i][j]=='.') continue;
                else if(solve(board,i,j)==false) return false;
            }
        }
        return true;
    }
    bool fun(vector<vector<char>>& board,int row,int col){
        // base case
        if(row == 9){
            return true;
        }
        int newrow=col==8?row+1:row;
        int newcol=(col==8)?0:col+1;

        if(board[row][col]=='.'){
            for(int val=49;val<=57;val++){
                board[row][col]=(char)(val);
                
                if(isValidSudoku(board)){
                    if(fun(board,newrow,newcol)) return true;
                }
                board[row][col]='.';
            }
            return false;
        }
        else{
            return fun(board,newrow,newcol);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        fun(board,0,0);
    }
};