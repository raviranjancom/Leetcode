class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights){
        int n=words.size();
        string ans;
        for(int i=0;i<n;i++){
            int wt=0;
            for(auto &ch:words[i]){
                wt+=weights[ch-'a'];
            }
            wt=wt%26;
            ans+=(25-wt+'a');
        }
        return ans;
    }
};
