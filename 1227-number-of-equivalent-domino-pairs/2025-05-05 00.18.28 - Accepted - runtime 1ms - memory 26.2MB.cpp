class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        map<vector<int>,int> mp;
        for(int i=0;i<n;i++){
            sort(dominoes[i].begin(), dominoes[i].end());
            mp[dominoes[i]]++;
        }

        int count=0;
        for(auto it : mp){
            int m=it.second;
            count+=(m*(m-1))/2;
        }
        return count;
    }
};
