class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars){
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int maxh=1,maxv=1,x=1,y=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i-1]==hBars[i]-1){
                x++;
            }
            else{
                x=1;
            }
            maxh=max(maxh,x);
        }
        for(int i=1;i<vBars.size();i++){
            if(vBars[i-1]==vBars[i]-1){
                y++;
            }
            else{
                y=1;
            }
            maxv=max(maxv,y);
        }
        int side=min(maxh,maxv)+1;
        return side*side;
    }
};
