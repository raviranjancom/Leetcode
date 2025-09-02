class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pair<double,int>> ratio;

        for(int i=0;i<n;i++){
            double current_ratio = (double)classes[i][0]/(double)classes[i][1];
            double new_ratio = (double)(classes[i][0]+1)/(double)(classes[i][1]+1);
            ratio.push({new_ratio - current_ratio,i});
        }

        while(extraStudents--){
            pair<double,int> x=ratio.top(); ratio.pop();

            classes[x.second][0]++;
            classes[x.second][1]++;

            double current_ratio = (double)classes[x.second][0]/(double)classes[x.second][1];
            double new_ratio = (double)(classes[x.second][0]+1)/(double)(classes[x.second][1]+1);
            ratio.push({new_ratio - current_ratio,x.second});
        }
        double ans=0.0;
        for(int i=0;i<n;i++){
            ans+=(double)classes[i][0]/(double)classes[i][1];
        }
        return ans/n;
    }
};