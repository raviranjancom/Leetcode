class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        int p=0;
        while(n>0){
            int k=n%10;
            if(k!=0) ans.push_back(k*pow(10,p));
            p++;
            n=n/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
