class Solution {
public:
    bool check(vector<pair<int,int>> &ds, int p,int q, int i,int j){
        for(int r=0;r<ds.size();r++){
            if(ds[r].first >= p && ds[r].second >= q && ds[r].first <= i && ds[r].second <= j){
                return false;
            }
        }
        return true;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<pair<int,int>> ds;
        // storing the postion of all zeros
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    ds.push_back({i,j});
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int k=0;
                while(i+k<n && j+k<m){
                    if(!check(ds,i,j,i+k,j+k)){
                        break;
                    }
                    k++;
                }
                ans+=k;
            }
        }
        return ans;
    }
};
