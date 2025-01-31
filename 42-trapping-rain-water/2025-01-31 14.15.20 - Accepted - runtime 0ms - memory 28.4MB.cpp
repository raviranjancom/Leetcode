class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int a=-1;
        vector<int> left,right;
        for(int i=0;i<n;i++){
            a=max(a,height[i]);
            left.push_back(a);
        }
        a=-1;
        for(int i=n-1;i>=0;i--){
            a=max(a,height[i]);
            right.push_back(a);
        }
        reverse(right.begin(), right.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int p=min(left[i], right[i]);
            int q=height[i];
            ans+=(p-q);
        }
        return ans;
    }
};
