class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxval=0;
        int n=gain.size();
        for(int i=1;i<n;i++){
            gain[i]=gain[i] + gain[i-1];
            maxval=max(gain[i], maxval);
        }
        return maxval;
    }
};

