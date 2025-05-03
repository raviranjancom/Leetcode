class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int t=tops[0],b=bottoms[0];
        int top_count=1,bottom_count=1,top_swap=0,bottom_swap=0;
        for(int i=1;i<n;i++){
            if(t==tops[i] || t==bottoms[i]){
                top_count++;
                if(t==bottoms[i] && t!=tops[i]){
                    top_swap++;
                }
            }
            if(b==tops[i] || b==bottoms[i]){
                bottom_count++;
                if(b==tops[i] && b!=bottoms[i]){
                    bottom_swap++;
                }
            }
        }
        if(top_count==n || bottom_count==n){
            if(top_count == n && bottom_count== n){
                return min(top_swap,bottom_swap);
            }
            else if(top_count == n){
                return top_swap;
            }
            else{
                return bottom_swap;
            }
        }
        return -1;
    }
};
