class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int i=1;
        while(i<n){
            if(i%10!=0 && (n-i)%10!=0) return {i,n-i};
            i++;
        }
        return {1,0};
    }
};