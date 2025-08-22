class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> rows(n,0);
        vector<int> cols(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rows[i]=rows[i] || grid[i][j];
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cols[i]=cols[i] || grid[j][i];
            }
        }

        int x=-1,y=-1,p=-1,q=-1;
        for(int i=0;i<n;i++){
            if(rows[i]==1 && x==-1){
                x=i;
                y=i;
            }
            if(rows[i]==1){
                y=i;
            }

        }
        for(int i=0;i<m;i++){
            if(cols[i]==1 && p==-1){
                p=i;
                q=i;
            }
            if(cols[i]==1){
                q=i;
            }
        }
        return (y-x+1)*(q-p+1);
    }
};