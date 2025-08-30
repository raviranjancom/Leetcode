class Solution {
public:
    bool solve(vector<vector<char>>& board,int cr,int cc){
        // check col
        int hash_row[10]={0};
        for(int row=0;row<9;row++){
            if(board[row][cc]=='.') continue;
            else if(hash_row[board[row][cc]-'0']==0){
                hash_row[board[row][cc]-'0']++;
            }
            else{
                return false;
            }
        }
        // check row
        int hash_col[10]={0};
        for(int col=0;col<9;col++){
            if(board[cr][col]=='.') continue;
            else if(hash_col[board[cr][col]-'0']==0){
                hash_col[board[cr][col]-'0']++;
            }
            else{
                return false;
            }
        }
        // checking square
        int start_row=3*(cr/3);
        int end_row=3*((cr/3)+1);
        end_row-=1;
        int start_col=3*(cc/3);
        int end_col=3*((cc/3)+1);
        end_col-=1;
        

        int hash_square[10]={0};
        for(int i=start_row;i<=end_row;i++){
            for(int j=start_col;j<=end_col;j++){
                if(board[i][j]=='.') continue;
                else if(hash_square[board[i][j]-'0']==0){
                    hash_square[board[i][j]-'0']++;
                }
                else{
                    return false;
                }
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
};
