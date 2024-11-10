class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=0,t=0;
        int n=height.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int b=j-i;
                int m;
                if(height[i] > height[j]) m=height[j];
                else m=height[i];

                t=m*b;
                if(t>max) max=t;
            }
        }
        return max;
    }
};
