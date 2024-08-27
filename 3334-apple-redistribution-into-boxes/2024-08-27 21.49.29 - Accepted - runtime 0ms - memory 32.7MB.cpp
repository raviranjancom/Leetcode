class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int n=size(apple);
        int m=size(capacity);
        int s=0;
        for(int i=0;i<n;i++){
            s+=apple[i];
        }
        int c=0,t=0;
        for(int i=0;i<m;i++){
            if(c>=s) return t;
            c+=capacity[m-1-i];
            t++;
        }
        return t;
    }
};