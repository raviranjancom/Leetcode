class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left,right;
        int k=0;
        for(int i=0;i<n;i++){
            if(height[i]>=height[k]){
                left.push_back(i);
                k=i;
            }
            else{
                left.push_back(k);
            }
        }
        k=n-1;
        for(int i=n-1;i>=0;i--){
            if(height[i]>=height[k]){
                right.push_back(i);
                k=i;
            }
            else{
                right.push_back(k);
            }
        }
        reverse(right.begin(),right.end());
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(left[i]!=i && right[i]!=i){
                ans+=min(height[left[i]],height[right[i]])-height[i];
            }
        }
        return ans;
    }
};
