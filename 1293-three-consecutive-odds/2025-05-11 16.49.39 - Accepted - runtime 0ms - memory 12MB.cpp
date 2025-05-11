class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int s=0;
        for(int i=0;i<n;i++){
            if(arr[i]&1!=0){
                s++;
            }
            else{
                s=0;
            }
            if(s>2) return true;
        }
        return false;
    }
};