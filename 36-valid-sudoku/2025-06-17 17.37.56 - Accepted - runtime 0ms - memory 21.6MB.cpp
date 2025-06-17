class Solution {
public:
    bool isvalid(vector<vector<char>> & board,int row,int col){
        int p=0,q=0,k=0;
        char ch=board[row][col];
        for(int i=0;i<9;i++){
            if(board[row][i]==ch){
                p++;
                if(p>1) return false;
            }
            if(board[i][col]==ch){
                q++;
                if(q>1) return false;
            }

            int r=row/3,c=col/3;
            if(board[r*3 + i/3][c*3 + i%3]==ch){
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
