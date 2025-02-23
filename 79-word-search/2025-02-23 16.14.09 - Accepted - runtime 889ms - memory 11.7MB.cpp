class Solution {
public:
    bool check(vector<vector<char>> &board, string &ans, string word, int i, int j, int n, int m, int p){
        if(p==word.size()){
            return true;
        }
        else if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[p]){
            return false;
        }
        char x=board[i][j];
        ans+=x;
        board[i][j]='0';

        bool r=check(board, ans, word, i-1, j, n, m, p+1) || check(board, ans, word, i, j-1, n, m, p+1) || check(board, ans, word, i+1, j, n, m, p+1) || check(board, ans, word, i, j+1, n, m, p+1);

        board[i][j]=x;
        ans.pop_back();

        return r;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                string ans = "";
                if (board[i][j] == word[0] && check(board, ans, word, i, j, n, m, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
