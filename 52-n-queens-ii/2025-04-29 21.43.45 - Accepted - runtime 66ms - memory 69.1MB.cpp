class Solution {
public:
    bool checkrow(vector<string> qus, int cr, int cc, int n){
        // checking rows
        for(int i=0;i<n;i++){
            if(qus[cr][i]=='Q'){
                return false;
            }
        }
        return true;
    }

    bool checkcol(vector<string> qus, int cr, int cc, int n){
        // checking columns
        for(int j=0;j<n;j++){
            if(qus[j][cc]=='Q'){
                return false;
            }
        }
        return true;
    }

    bool checkdia1(vector<string> qus, int cr, int cc, int n){
        // checking diagonals on left
        int x=cr,y=cc;
        while(x>=0 && y>=0){
            if(qus[x][y]=='Q'){
                return false;
            }
            x--;
            y--;
        }
        return true;
    }

    bool checkdia2(vector<string> qus, int cr, int cc, int n){
        // checking right diagonal
        int x1=cr, y1=cc;
        while(x1>=0 && y1<n){
            if(qus[x1][y1]=='Q'){
                return false;
            }
            x1--;
            y1++;
        }
        return true;
    }

    void place(vector<string> &qus,vector<int> &ans, int cr, int n){
        if(cr==n){
            ans[0]++;
            return ;
        }
        for(int j=0;j<n;j++){
            if(checkcol(qus, cr, j, n) && checkdia1(qus, cr,j,n) && checkdia2(qus,cr,j,n)){
                qus[cr][j]='Q';
                place(qus,ans,cr+1,n);
                qus[cr][j]='.';
            }
        }
    }

    int totalNQueens(int n) {
        // create an empty board
        vector<int> ans(1,0);
        vector<string> qus(n, string(n, '.'));
        place(qus,ans,0,n);
        int r=ans[0];
        return r;
    }
};

