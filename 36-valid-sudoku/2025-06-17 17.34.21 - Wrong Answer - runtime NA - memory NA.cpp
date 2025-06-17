class Solution {
public:
    bool isvalid(vector<vector<char>> & board,int row,int col){
        int p=0,q=0,k=0;
        for(int i=0;i<9;i++){
            if(board[row][i]==board[row][col]){
                p++;
                if(p>1) return false;
            }
            if(board[i][col]==board[row][col] && i!=row){
                q++;
                if(q>1) return false;
            }

            int r=row/3,c=col/3;
            if(board[r*3 + i/3][c*3 + i%3]==board[row][col]){
                k++;
                if(k>1) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!isvalid(board, i, j) && board[i][j]!='.'){
                    return false;
                }
            }
        }
        return true;
    }
};
