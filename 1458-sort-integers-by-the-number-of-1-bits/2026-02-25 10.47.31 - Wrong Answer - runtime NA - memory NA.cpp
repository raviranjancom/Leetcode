class Solution {
public:
    static bool comp(int a,int b){
        if(__builtin_popcount(a)<__builtin_popcount(b)){
            return true;
        }
        return a<b;
    }
    vector<int> sortByBits(vector<int>& arr){
        int n=arr.size();
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};
