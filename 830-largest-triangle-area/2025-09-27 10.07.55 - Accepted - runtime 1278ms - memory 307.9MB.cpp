class Solution {
public:
    double area(double x,double y,double z){
        double s=(x+y+z)/2.0;
        return pow(s*(s-x)*(s-y)*(s-z), 0.5);
    }
    double len(vector<int> a,vector<int> b){
        return pow(pow(a[0]-b[0],2) + pow(a[1]-b[1],2),0.5);
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && i!=k){
                        double x=len(points[i],points[j]);
                        double y=len(points[j],points[k]);
                        double z=len(points[k],points[i]);
                        ans=max(ans, area(x,y,z));
                    }
                }
            }
        }
        return ans;
    }
};
