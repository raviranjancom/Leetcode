class Spreadsheet {
public:
    vector<vector<int>> table;
    Spreadsheet(int rows) {
        table.resize(rows, vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        string s(cell.begin()+1,cell.end());
        int x=stoi(s)-1;
        int y=cell[0]-'A';
        table[x][y]=value;
    }
    
    void resetCell(string cell) {
        string s(cell.begin()+1,cell.end());
        int x=stoi(s)-1;
        int y=cell[0]-'A';
        table[x][y]=0;
    }
    
    int getValue(string formula) {
        int index=formula.find('+');
        string a=formula.substr(1,index-1);
        string b=formula.substr(index+1,formula.size()-index-1);

        string s1(a.begin()+1,a.end()),s2(b.begin()+1,b.end());
        int x=(isdigit(a[0])) ? stoi(a): table[stoi(s1)-1][a[0]-'A'];
        int y=(isdigit(b[0])) ? stoi(b): table[stoi(s2)-1][b[0]-'A'];

        return x+y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */