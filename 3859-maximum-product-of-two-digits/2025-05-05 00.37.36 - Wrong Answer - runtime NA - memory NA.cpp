class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;
        int num=n;
        while(num>0){
            int last=num%10;
            if(last!=0) v.push_back(last);
            num=num/10;
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        return v[0];
    }
};