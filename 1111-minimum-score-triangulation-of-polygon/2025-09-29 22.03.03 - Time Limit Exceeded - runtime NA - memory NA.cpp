class Solution {
public:
    int solve(vector<int>& values, int start, int end){
        if(end-start<2){
            return 0;
        }
        int ans=INT_MAX;
        for(int i=start+1;i<end;i++){
            int x=solve(values,start,i)+values[start]*values[i]*values[end]+solve(values,i,end);
            ans=min(ans,x);
        }
        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        return solve(values,0,n-1);
    }
};