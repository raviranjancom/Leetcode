class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int no_of_classes=classes.size();
        int n=extraStudents;
        for(int i=0;i<n;i++){
            float difference=0.0;
            int key=0;
            for(int j=0;j<no_of_classes;j++){
                float x=(float)(classes[j][0])/(float)(classes[j][1]);
                float y=(float)(classes[j][0]+1)/(float)(classes[j][1]+1);
                
                // maximum difference wale ko consider kro
                if(y-x > difference){
                    difference=y-x;
                    key=j;
                }
            }
            classes[key][0]++;
            classes[key][1]++;
        }
        // calculating
        float ans=0.0;
        for(int i=0;i<no_of_classes;i++){
            ans+=(float)(classes[i][0])/(float)(classes[i][1]);
        }
        ans=ans/no_of_classes;
        return ans;
    }
};
