class Solution {
public:
    double separateSquares(vector<vector<int>>& squares){
        double l=INT_MAX,r=INT_MIN;
        for(auto &it:squares){
            l=min(l,(double)it[1]);
            r=max(r,(double)(it[1]+it[2]));
        }
        while(r-l>1e-5){
            double mid=(double)(l+r)/2.0;
            double upperArea=0.0;
            double lowerArea=0.0;
            for(auto &it:squares){
                double top=(double)(it[1]+it[2]);
                double h1=max(0.0, top - max(mid, (double)it[1]));
                double h2=max(0.0, min(mid, top) - it[1]);

                upperArea+=h1*(double)it[2];
                lowerArea+=h2*(double)it[2];
            }
            if(upperArea<=lowerArea){
                r=mid;
            }
            else{
                l=mid;
            }
        }
        return r;
    }
};
