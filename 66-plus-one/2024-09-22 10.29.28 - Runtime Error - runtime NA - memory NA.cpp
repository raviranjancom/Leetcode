class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=size(digits);
        long long a=0;
        for(int i=0;i<n;i++){
            a=a*10+digits[i];
        }
        a++;
        vector<int> ans;
        while(a>0){
            ans.push_back(a%10);
            a/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};