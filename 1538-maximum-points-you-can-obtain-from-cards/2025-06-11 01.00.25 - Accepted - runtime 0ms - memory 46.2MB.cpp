class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=k-1,r=n-1;
        int point=0,maxpoint=0;
        for(int i=0;i<k;i++){
            point+=cardPoints[i];
        }

        maxpoint=max(maxpoint, point);
        while(l>-1 && r<n){
            point=point+cardPoints[r]-cardPoints[l];
            maxpoint=max(maxpoint, point);
            r--;
            l--;
        }
        return maxpoint;
    }
};