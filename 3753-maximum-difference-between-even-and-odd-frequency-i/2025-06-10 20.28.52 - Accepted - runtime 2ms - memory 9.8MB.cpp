class Solution {
public:
    int maxDifference(string s) {
        int n=s.length();
        int min_odd=INT_MAX,min_even=INT_MAX;
        int max_odd=INT_MIN, max_even=INT_MIN;
        map<char,int> hash;
        for(int i=0;i<n;i++){
            hash[s[i]]++;
        }
        for(auto i : hash){
            if(i.second%2==1){
                min_odd=min(min_odd, i.second);
                max_odd=max(max_odd, i.second);
            }
            else{
                min_even=min(min_even, i.second);
                max_even=max(max_even, i.second);
            }
        }
        return (max_odd - min_even);
    }
};
