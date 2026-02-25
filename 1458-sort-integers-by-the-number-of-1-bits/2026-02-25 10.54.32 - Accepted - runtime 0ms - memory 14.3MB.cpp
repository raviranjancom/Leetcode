class Solution {
public:
    static bool comp(int a,int b){
        int x=__builtin_popcount(a);
        int y=__builtin_popcount(b);
        if(!(x==y)) return x<y;
        return a<b;
    }
    vector<int> sortByBits(vector<int>& arr){
        int n=arr.size();
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};
