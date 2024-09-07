class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int x=0,y=0;
        
        x+=int(coordinate1[0]-97);
        x+=int(coordinate1[1]-48);

        y+=int(coordinate2[0]-97);
        y+=int(coordinate2[1]-48);

        if(x%2==0 && y%2==0) return true;
        if(y%2==1 && x%2==1) return true;
        else return false;
    }
};
