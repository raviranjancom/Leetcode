class Solution {
public:
    double diagonal_length(vector<int> &ds){
        return pow((ds[0]*ds[0] + ds[1]*ds[1]), 0.5);
    }
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        double max_len=0.0;
        int area=0;
        for(int i=0;i<n;i++){
            double x=diagonal_length(dimensions[i]);
            if(max_len<x){
                area=dimensions[i][0] * dimensions[i][1];
                max_len=x;
            }
        }
        return area;
    }
};
