int fact(int x){
    if (x==0||x==1) return 1;
    else return x*fact(x-1);
}
int fun(int i,int j){
    return fact(i)/(fact(j)*fact(i-j));
}
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        int a;
        for(int i=0;i<numRows;i++){
            vector<int> t;
            for(int j=0;j<i+1;j++){
                a=fun(i,j);
                t.push_back(a);
            }
            v.push_back(t);
        }
        return v;
    }
};