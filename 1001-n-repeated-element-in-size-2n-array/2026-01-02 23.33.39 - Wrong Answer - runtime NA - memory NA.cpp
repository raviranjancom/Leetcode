class Solution {
public:
    int repeatedNTimes(vector<int>& arr){
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(i+2<n && arr[i]==arr[i+2]){
                return arr[i];
            }
            if(i+1<n && arr[i]==arr[i+1]){
                return arr[i];
            }
        }
        return 0;
    }
};
