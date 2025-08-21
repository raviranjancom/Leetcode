class Solution {
public:
    int arraycount(vector<int> &ds){
        int count=0,ans=0;
        for(int &it:ds){
            if(it==0){
                count=0;
            }
            else{
                count++;
            }
            ans+=count;
        }
        return ans;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> ds(m,1);
            for(int j=i;j<n;j++){
                for(int col=0;col<m;col++){
                    ds[col]=ds[col]&mat[j][col];
                }
                ans+=arraycount(ds);
            }
        }
        return ans;
    }
};