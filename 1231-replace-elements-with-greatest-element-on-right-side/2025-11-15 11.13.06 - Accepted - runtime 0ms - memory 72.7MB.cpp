class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int m=-1;
        for(int i=n-1;i>=0;i--){
            int temp=max(m,arr[i]);
            arr[i]=m;
            m=temp;
        }
        return arr;
    }
};