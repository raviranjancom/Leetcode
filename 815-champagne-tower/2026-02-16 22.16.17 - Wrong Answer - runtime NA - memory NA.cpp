class Solution {
public:
    vector<int> calculate(int n){
        vector<vector<int>> mat;
        for(int i=0;i<=n;i++){
            vector<int> ds;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i) ds.push_back(1);
                else{
                    int x=mat[i-1][j-1]+mat[i-1][j];
                    ds.push_back(x);
                }
            }
            mat.push_back(ds);
        }
        return mat.back();
    }
    double champagneTower(int poured, int query_row, int query_glass){
        int i=1;
        while(poured>=i){
            poured-=i;
            if(i-1==query_row) return 1.0;
            i++;
        }
        if(i-1==query_row){
            vector<int> mat=calculate(query_row);
            for(auto it:mat){
                cout<<it<<" ";
            }
            int sum=0;
            for(auto &it:mat){
                sum+=it;
            }
            double factor=((double)mat[query_glass])/((double)sum);
            return poured*factor;
        }
        return 0.0;
    }
};
