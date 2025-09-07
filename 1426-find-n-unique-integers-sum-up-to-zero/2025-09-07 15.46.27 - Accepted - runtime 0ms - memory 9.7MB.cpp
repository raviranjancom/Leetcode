class Solution {
public:
    vector<int> sumZero(int n) {
        int x=n/2;
        vector<int> ans;
        for(int i=(-1)*x; i<=x; i++){
            if(i==0 && n%2==0) continue;
            ans.push_back(i);
        }
        return ans;
    }
};